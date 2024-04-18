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
// Created by Wangyunlai on 2022/12/07
//

#pragma once

#include "sql/operator/physical_operator.h"
#include "storage/record/record_manager.h"
#include "common/rc.h"

class View;

/**
 * @brief 表扫描物理算子
 * @ingroup PhysicalOperator
 */
class ViewScanPhysicalOperator : public PhysicalOperator
{
public:
  ViewScanPhysicalOperator(View *view, bool readonly) 
      : view_(view), readonly_(readonly)
  {}

  virtual ~ViewScanPhysicalOperator()
  {
    if (nullptr != record_data_) free(record_data_);
  }

  std::string param() const override;

  PhysicalOperatorType type() const override
  {
    return PhysicalOperatorType::VIEW_SCAN;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override;

  void set_predicates(std::vector<std::unique_ptr<Expression>> &&exprs);

private:
  RC filter(RowTuple &tuple, bool &result);

private:
  View *                                   view_ = nullptr;
  Trx *                                    trx_ = nullptr;
  bool                                     readonly_ = false;
  RowTuple                                 tuple_;
  std::vector<std::unique_ptr<Expression>> predicates_; // TODO predicate to table tuple filter

  char *                                   record_data_ = nullptr;
  int                                      record_size_;
  Record                                   view_record_;
  std::unique_ptr<PhysicalOperator>        physical_oper_;
};