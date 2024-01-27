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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <vector>
#include <memory>

#include "common/rc.h"
#include "sql/expr/expression.h"
#include "sql/expr/tuple.h"
#include "sql/parser/value.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/join_stmt.h"
#include "storage/field/field.h"

class FieldMeta;
class FilterStmt;
class Db;
class Table;

struct FieldInfo {
  AttrType type;
  int length = 0;
  Field raw_field;
};

/**
 * @brief 表示select语句
 * @ingroup Statement
 */
class SelectStmt : public Stmt 
{
public:
  SelectStmt() = default;
  ~SelectStmt() override;

  StmtType type() const override { return StmtType::SELECT; }

public:
  static RC create(Db *db, const SelectSqlNode &select_sql, Stmt *&stmt);

public:
  const std::unordered_map<std::string, Table *> &current_tables() const { return current_tables_; }
  const std::vector<std::unique_ptr<Expression>> &expressions() const { return expressions_; }
  std::vector<std::unique_ptr<Expression>> &expressions() { return expressions_; }
  const std::set<Field> &used_fields() const { return used_fields_; }
  const std::vector<std::set<Field>> reference_fields() const { return reference_fields_; }
  std::unique_ptr<FilterStmt> &filter_stmt() { return filter_stmt_; }
   std::shared_ptr<TupleSchema> schema() { return schema_; }
  std::unique_ptr<JoinStmt> &join_stmt() { return join_stmt_; }
  const std::vector<FieldInfo> &types() const { return types_; }

private:
  std::unique_ptr<JoinStmt> join_stmt_;

  std::set<Field> used_fields_;                              // 当前查询会生成的scan中所有用到的field
  std::vector<std::set<Field>> reference_fields_;            // 每个表达式用到的field
  std::unordered_map<std::string, Table *> current_tables_; // 当前查询的表名
  std::vector<std::unique_ptr<Expression>> expressions_;    // 所有表达式
  std::shared_ptr<TupleSchema> schema_;                     // 所有要输出的tuple的schema
  std::unique_ptr<FilterStmt> filter_stmt_;                  // where 子句
  std::vector<FieldInfo> types_;
};
