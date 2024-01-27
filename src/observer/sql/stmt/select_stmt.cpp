/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/6/6.
//

#include "sql/stmt/select_stmt.h"
#include "sql/stmt/join_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

SelectStmt::~SelectStmt() {}

static void wildcard_fields(Table *table, std::string name, std::vector<std::unique_ptr<Expression>> &field_metas) {
  assert(name.size());
  Expression *expr;
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    FieldExpr::create(table, table_meta.field(i), name, expr);
    field_metas.emplace_back(expr);
  }
}

RC SelectStmt::create(Db *db, const SelectSqlNode &select_sql, Stmt *&stmt)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  // collect tables in `from` statement
  std::vector<std::string> tables;
  std::unordered_map<std::string, Table *> table_map;
  ConjunctionExprSqlNode *conditions = nullptr;
  auto add_conjunction = [&](ConjunctionExprSqlNode *node) {
    if (conditions == nullptr)
      conditions = node;
    else {
      conditions = new ConjunctionExprSqlNode(ConjunctionType::AND, conditions, node);
    }
  };

  RC rc = RC::SUCCESS;
  std::unique_ptr<JoinStmt> join_stmt;
  std::unordered_map<std::string, Table *> current_tables;
  if (select_sql.tables) {
    JoinStmt *join = nullptr;
    rc = JoinStmt::create(db, select_sql.tables, join, tables, current_tables);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to create join stmt");
      return rc;
    }
    join_stmt.reset(join);
  }

  table_map = current_tables;
  std::reverse(tables.begin(), tables.end());

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = table_map[tables[0]];
  }

  std::shared_ptr<TupleSchema> schema = std::make_shared<TupleSchema>();

  std::set<Field> groupbys;
  for (auto *x : select_sql.groupbys) {
    Expression *field;
    RC rc = FieldExpr::create(db, default_table, &table_map, x, field);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    if (field->type() != ExprType::FIELD) {
      LOG_ERROR("FieldExpr::create not get field expr, get %s", field->type());
      return RC::INTERNAL;
    }
    groupbys.insert(static_cast<FieldExpr *>(field)->field());
    delete field;
  }
  std::set<Field> used_fields = groupbys;
  
  // collect query fields in `select` statement
  std::vector<Field> query_fields;
  std::vector<std::unique_ptr<Expression>> expressions;
  std::unordered_map<int, std::string> expr_alias;
  for (int i = 0; i < select_sql.attributes.size(); i++) {
    const auto *attribute = select_sql.attributes[i];
    const ExprSqlNode *expression = attribute->expr;

    if (expression->type() == ExprType::STAR) {
      if (attribute->alias.size()) {
        LOG_WARN("alias to star");
        return RC::INVALID_ARGUMENT;
      }
      for (auto &name : tables) {
        auto it = table_map.find(name);
        if (it == table_map.end()) {
          return RC::INTERNAL;
        }
        wildcard_fields(it->second, name, expressions);
      }
    } else if (expression->type() == ExprType::FIELD && expression->get_field()->field_name == "*") {
      if (attribute->alias.size()) {
        LOG_WARN("alias to star");
        return RC::INVALID_ARGUMENT;
      }
      auto table_name = expression->get_field()->table_name;
      auto it = table_map.find(table_name);
      if (it == table_map.end()) {
        LOG_WARN("table %s not exists", table_name.c_str());
        return RC::SCHEMA_FIELD_NOT_EXIST;
      }
      wildcard_fields(it->second, table_name, expressions);
    } else {
      Expression *expr;
      RC rc = Expression::create(db, default_table, &table_map, expression, expr, nullptr);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to parse expression, rc=%s", strrc(rc));
        return rc;
      }
      if (attribute->alias.size()) {
        expr_alias[expressions.size()] = attribute->alias;
        expr->set_name(attribute->alias);
      }
      expressions.emplace_back(expr);
    }
  }

  std::vector<std::set<Field>> reference_fields(expressions.size());
  std::set<Field> attr_used_fields = groupbys;

  std::map<std::string, std::string> table_alias;
  for (auto &x : current_tables) {
    if (x.first != x.second->name())
      table_alias[x.second->name()] = x.first;
  }

  std::vector<FieldInfo> types;

  auto append_cell = [&](Expression *expression, std::string alias = "") {
    FieldInfo type;
    type.type = expression->value_type();
    type.length = attr_type_to_size(type.type);
    if (alias.size()) {
      schema->append_cell(alias.c_str());
    } else if (expression->type() == ExprType::FIELD) {
      Field &field = static_cast<FieldExpr *>(expression)->field();
      type.length = field.meta()->len();
      if (tables.size() == 1) {
        schema->append_cell(TupleCellSpec(field.table_name(), field.field_name(), field.field_name()));
      } else {
        auto it = table_alias.find(field.table_name());
        if (it != table_alias.end()) {
          schema->append_cell(it->second.c_str(), field.field_name());
        } else {
          schema->append_cell(field.table_name(), field.field_name());
        }
      }
    } else {
      schema->append_cell(expression->name().c_str());
    }
    if (expression->type() == ExprType::FIELD) {
      type.raw_field = static_cast<FieldExpr *>(expression)->field();
    }
    types.push_back(type);
  };

  for (int i = 0; i < expressions.size(); i++) {
    auto fields = expressions[i]->reference_fields();
    attr_used_fields.insert(fields.begin(), fields.end());
    auto it = expr_alias.find(i);
    if (it != expr_alias.end()) {
      append_cell(expressions[i].get(), it->second);
    } else {
      append_cell(expressions[i].get());
    }
    reference_fields[i].swap(fields);
  }

  used_fields.insert(attr_used_fields.begin(), attr_used_fields.end());

  std::set<Field> filter_used_fields;

  LOG_INFO("got %d tables in from stmt and %d fields in query stmt", tables.size(), expressions.size());

  // create filter statement in `where` statement
  std::unique_ptr<FilterStmt> filter_stmt;
  if (select_sql.conditions != nullptr) {
    add_conjunction(select_sql.conditions);
  }
  if (conditions != nullptr) {
    FilterStmt *stmt = nullptr;
    RC rc = FilterStmt::create(db, default_table, &table_map, conditions, stmt, nullptr);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot construct filter stmt");
      return rc;
    }
    filter_stmt.reset(stmt);
    auto &expr = filter_stmt->filter_expr();
    filter_used_fields = expr->reference_fields();
  }
  
  used_fields.insert(filter_used_fields.begin(), filter_used_fields.end());

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();

  // TODO add expression copy
  select_stmt->join_stmt_.swap(join_stmt);
  select_stmt->used_fields_ = used_fields;
  select_stmt->reference_fields_.swap(reference_fields);
  select_stmt->expressions_.swap(expressions);
  select_stmt->current_tables_.swap(current_tables);
  select_stmt->filter_stmt_ = std::move(filter_stmt);
  select_stmt->schema_ = schema;

  stmt = select_stmt;
  return RC::SUCCESS;
}
