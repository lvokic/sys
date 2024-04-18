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
// Created by Wangyunlai on 2021/5/12.
//

/* 
 * 用来区分Table和View
 */

#pragma once

#include <cstdint>

class TableMeta;

enum class BaseTabletype
{
  TABLE_TYPE,
  VIEW_TYPE
};

class BaseTable
{
public:
  BaseTable() = default;

  virtual int32_t table_id() const = 0;
  virtual const char *name() const = 0;
  virtual const TableMeta &table_meta() const = 0;
public:
  void set_view_type()
  {
    base_type_ = BaseTabletype::VIEW_TYPE;
  }
  bool is_view() const
  {
    return BaseTabletype::VIEW_TYPE == base_type_;
  }
  bool is_table() const
  {
    return BaseTabletype::TABLE_TYPE == base_type_;
  }

private:
  BaseTabletype base_type_ = BaseTabletype::TABLE_TYPE;
};