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

#include "common/rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/orderby_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "sql/stmt/filter_stmt.h"

RC OrderByStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      const std::vector<OrderBySqlNode> &orderby_sql_nodes, OrderByStmt *&stmt,
      std::vector<std::unique_ptr<Expression>> &&exprs)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  std::vector<std::unique_ptr<OrderByUnit >> tmp_units;
  
  for(auto &node : orderby_sql_nodes)
  {
    tmp_units.emplace_back(std::make_unique<OrderByUnit>(node.expr,node.is_asc));//这里 order by unit 中的指针是独享的
  }
  // everything alright
  stmt = new OrderByStmt();
  stmt->set_orderby_units(std::move(tmp_units));
  stmt->set_exprs(std::move(exprs));

  return rc;
}