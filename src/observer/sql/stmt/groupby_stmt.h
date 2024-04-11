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

#pragma once

#include <vector>
#include <unordered_map>
#include "common/rc.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include "sql/expr/expression.h"

class Db;
class Table;
class FieldMeta;

class GroupByStmt : Stmt{
public:
  GroupByStmt() = default;
  virtual ~GroupByStmt() = default;

  StmtType type() const override
  {
    return StmtType::GROUPBY;
  }
public:
  std::vector<std::unique_ptr<AggrFuncExpr>> &get_agg_exprs()
  {
    return agg_exprs_;
  }
  std::vector<std::unique_ptr<FieldExpr>> &get_field_exprs()
  {
    return field_exprs_;
  }
  std::vector<std::unique_ptr<FieldExpr>>& get_groupby_fields()
  {
    return groupby_fields_;
  }
  void set_agg_exprs(std::vector<std::unique_ptr<AggrFuncExpr>> &&agg_exprs)
  {
    agg_exprs_ = std::move(agg_exprs);
  }
  void set_field_exprs(std::vector<std::unique_ptr<FieldExpr>> &&field_exprs)
  {
    field_exprs_ = std::move(field_exprs);
  }
  void set_groupby_fields(std::vector<std::unique_ptr<FieldExpr>>&& groupby_fields) {
    groupby_fields_ = std::move(groupby_fields);
  }
public:
  static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      const GroupBySqlNode *groupby_node, GroupByStmt *&stmt,
      std::vector<std::unique_ptr<AggrFuncExpr>>&& agg_exprs,
      std::vector<std::unique_ptr<FieldExpr>>&& field_exprs);

private:
  std::vector<std::unique_ptr<FieldExpr>> groupby_fields_; // group by clause
  std::vector<std::unique_ptr<AggrFuncExpr>> agg_exprs_; // 聚集函数表达式
  std::vector<std::unique_ptr<FieldExpr>> field_exprs_; // 非聚集函数中的字段表达式
};