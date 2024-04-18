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
// Created by Meiyi
//

#include "sql/parser/parse_defs.h"
#include "sql/expr/expression.h"

void OrderBySqlNode::deep_copy(const OrderBySqlNode &src)
{
  if (nullptr != src.expr) {
    expr = src.expr->deep_copy().release();
  }
  is_asc = src.is_asc;
}

void InnerJoinSqlNode::deep_copy(const InnerJoinSqlNode &src)
{
  base_relation = src.base_relation;
  join_relations.clear();
  join_relations = src.join_relations;
  conditions.clear();
  for (size_t i = 0; i < src.conditions.size(); ++i) {
    conditions.emplace_back(src.conditions[i]->deep_copy().release());
  }
}

void SelectSqlNode::deep_copy(const SelectSqlNode &src)
{
  project_exprs.clear();
  for (size_t i = 0; i < src.project_exprs.size(); i++) {
    project_exprs.emplace_back(src.project_exprs[i]->deep_copy().release());
  }
  relations.clear();
  for (size_t i = 0; i < src.relations.size(); i++) {
    InnerJoinSqlNode dst;
    dst.deep_copy(src.relations[i]);
    relations.emplace_back(std::move(dst));
  }
  if (nullptr != src.conditions) {
    conditions = src.conditions->deep_copy().release();
  }
  orderbys.clear();
  for (size_t i = 0; i < src.orderbys.size(); i++) {
    OrderBySqlNode dst;
    dst.deep_copy(src.orderbys[i]);
    orderbys.emplace_back(std::move(dst));
  }
  groupby_exprs.clear();
  for (size_t i = 0; i < src.groupby_exprs.size(); i++) {
    groupby_exprs.emplace_back(src.groupby_exprs[i]->deep_copy().release());
  }
  if (nullptr != src.having_conditions) {
    having_conditions = src.having_conditions->deep_copy().release();
  }
}