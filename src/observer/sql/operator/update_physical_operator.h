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
// Created by WangYunlai on 2023/4/25.
//

#pragma once

#include "sql/operator/physical_operator.h"
#include "sql/optimizer/physical_plan_generator.h"
#include "sql/stmt/update_stmt.h"

class UpdatePhysicalOperator : public PhysicalOperator {
private:
  PhysicalOperatorType type() const { return PhysicalOperatorType::UPDATE; }

  virtual RC open(Trx *trx);
  virtual RC next() { return RC::RECORD_EOF; }
  virtual RC close() { return RC::SUCCESS; }

  virtual Tuple *current_tuple() { return nullptr; }

  friend class PhysicalPlanGenerator;

private:
  RC insert(std::vector<char> &v, RID &rid);
  RC insert_all(std::vector<std::vector<char>> &v);
  RC remove_all(const std::vector<RID> &rids);
  RC update(std::vector<char> v, std::vector<Value> &values, RID &rid);

  void rollback();

private:
  std::vector<UpdateUnit> units_;
  Table *table_;
  std::vector<std::vector<char>> deleted_records_;
  std::vector<RID> inserted_records_;
  Trx *trx_ = nullptr;
};
