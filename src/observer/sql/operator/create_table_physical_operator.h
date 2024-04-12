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

#include "sql/operator/physical_operator.h"

class Db;
class Trx;
class CreateTableStmt;

/**
 * @brief 物理算子，建表
 * @ingroup PhysicalOperator
 */
class CreateTablePhysicalOperator : public PhysicalOperator
{
public:
  CreateTablePhysicalOperator(Db *db, std::string table_name, std::vector<AttrInfoSqlNode> attr_infos)
    : db_(db), table_name_(std::move(table_name)), attr_infos_(std::move(attr_infos))
  {}

  virtual ~CreateTablePhysicalOperator() = default;

  PhysicalOperatorType type() const override
  {
    return PhysicalOperatorType::CREATE_TABLE;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;
  Tuple *current_tuple() override;
  
private:
  Db *db_ = nullptr;
  std::string table_name_;
  std::vector<AttrInfoSqlNode> attr_infos_;
};