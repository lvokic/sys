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
// Created by Wangyunlai on 2022/12/07.
//

#pragma once

#include "sql/operator/logical_operator.h"

class Db;

/**
 * @brief CreateTable逻辑算子
 * @ingroup LogicalOperator
 */
class CreateTableLogicalOperator : public LogicalOperator 
{
public:
  CreateTableLogicalOperator(Db *db, const std::string &table_name, const std::vector<AttrInfoSqlNode> &attr_infos)
    : db_(db),table_name_(table_name), attr_infos_(attr_infos)
  {}
  virtual ~CreateTableLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::CREATE_TABLE;
  }

  std::string &table_name() 
  { 
    return table_name_; 
  }
  std::vector<AttrInfoSqlNode> &attr_infos()
  {
    return attr_infos_;
  }
  Db *get_db()
  {
    return db_;
  }

private:
  Db *db_ = nullptr;
  std::string table_name_;
  std::vector<AttrInfoSqlNode> attr_infos_;
};