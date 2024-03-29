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
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/update_stmt.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "common/rc.h"
#include "sql/expr/expression.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/value.h"
#include "sql/stmt/select_stmt.h"
#include <utility>

RC UpdateStmt::create(Db *db, const UpdateSqlNode &update, Stmt *&stmt) {
  Table *table = db->find_table(update.relation_name.c_str());
  if (table == nullptr) {
    LOG_WARN("table %s not exists", update.relation_name.c_str());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  std::vector<UpdateUnit> units;
  RC rc = RC::SUCCESS;
  std::unordered_map<std::string, Table *> table_map;
  table_map.emplace(table->name(), table);
  std::set<Field> used_fields;
  for (auto x : update.sets) {
    const FieldMeta *field_meta;
    field_meta = table->table_meta().field(x->field_name.c_str());
    if (field_meta == nullptr) {
      LOG_WARN("field %s not exist in table %s", x->field_name.c_str(), update.relation_name.c_str());
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }
    Expression *value_expr;
    rc = Expression::create(db, table, &table_map, x->expr, value_expr, nullptr);
    if (rc != RC::SUCCESS)
      return rc;
    if (value_expr->type() == ExprType::VALUE) {
      Value value;
      static_cast<ValueExpr *>(value_expr)->get_value(value);
    }
    UpdateUnit unit;
    unit.field = Field(table, field_meta);
    unit.value.reset(value_expr);
    units.push_back(std::move(unit));
  }
  FilterStmt *filter = nullptr;
  if (update.conditions) {
    rc = FilterStmt::create(db, table, &table_map, update.conditions, filter, nullptr);
    if (rc != RC::SUCCESS) {
      LOG_WARN("fail to create filter stmt");
      return rc;
    }
  }
  auto *update_stmt = new UpdateStmt();
  update_stmt->table_ = table;
  update_stmt->units_.swap(units);
  update_stmt->filter_ = filter;
  stmt = update_stmt;
  return RC::SUCCESS;
}
