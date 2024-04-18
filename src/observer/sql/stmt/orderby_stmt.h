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

class OrderByUnit
{
public:
  OrderByUnit(Expression *expr, bool is_asc) : expr_(expr), is_asc_(is_asc) {}

  ~OrderByUnit() = default;

  void set_sort_type(bool sort_type) { is_asc_ = sort_type; }

  bool sort_type() const { return is_asc_; }

  std::unique_ptr<Expression> &expr() { return expr_; }

private:
  // sort type : true is asc
  bool                        is_asc_ = true;
  std::unique_ptr<Expression> expr_;
};

class OrderByStmt : Stmt{
public:
  OrderByStmt() = default;
  virtual ~OrderByStmt() = default;

  StmtType type() const override
  {
    return StmtType::ORDERBY;
  }
public:
  void set_orderby_units(std::vector<std::unique_ptr<OrderByUnit>> &&orderby_units)
  {
    orderby_units_ = std::move(orderby_units);
  }
  void set_exprs(std::vector<std::unique_ptr<Expression>> &&exprs)
  {
    exprs_ = std::move(exprs);
  }
  std::vector<std::unique_ptr<OrderByUnit>>& get_orderby_units()
  {
    return orderby_units_;
  }
  std::vector<std::unique_ptr<Expression>>& get_exprs()
  {
    return exprs_;
  }
public:
  static RC create(Db *db, BaseTable *default_table, std::unordered_map<std::string, BaseTable *> *tables,
      const std::vector<OrderBySqlNode> &orderby_sql_nodes, OrderByStmt *&stmt,
      std::vector<std::unique_ptr<Expression>> &&exprs);

private:
  std::vector<std::unique_ptr<OrderByUnit >> orderby_units_; //排序列

  ///在 create order by stmt 之前提取 select clause 后的 field_expr (非a gg_expr 中的)和 agg_expr
  std::vector<std::unique_ptr<Expression>> exprs_;
};

