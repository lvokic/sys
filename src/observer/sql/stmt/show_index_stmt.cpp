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
// Created by Wangyunlai on 2023/6/14.
//

#include "sql/stmt/show_index_stmt.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

RC ShowIndexStmt::create(Db *db, const ShowIndexSqlNode &show_index_sql,  Stmt *&stmt)
{
  RC rc = RC::SUCCESS;
  const char *table_name = show_index_sql.relation_name.c_str();

  if (nullptr == db || nullptr == table_name) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", db, table_name);
    rc = RC::INVALID_ARGUMENT;
  } else if (db->find_table(show_index_sql.relation_name.c_str()) == nullptr) {
    rc = RC::SCHEMA_TABLE_NOT_EXIST;
  } else {
    stmt = new ShowIndexStmt(table_name);
  }
  
  return rc;
}