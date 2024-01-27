/* Copyright (c) 2021OceanBase and/or its affiliates. All rights reserved.
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

#include "sql/stmt/insert_stmt.h"
#include "common/log/log.h"
#include "common/rc.h"
#include "sql/expr/expression.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include <utility>

InsertStmt::InsertStmt(Table *table, std::vector<std::vector<Value>> records) : table_(table), records_(records) {}

RC InsertStmt::create(Db *db, const InsertSqlNode &inserts, Stmt *&stmt)
{
  const char *table_name = inserts.relation_name.c_str();
  if (nullptr == db || nullptr == table_name || inserts.values.empty()) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, value_num=%d",
        db, table_name, static_cast<int>(inserts.values.size()));
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  auto &records = inserts.values;
  std::vector<std::vector<Value>> record_values;
  RC rc;
  for (auto &record_expr : records) {
    std::vector<Value> record;
    record.reserve(record_expr.size());
    for (int i = 0; i < record_expr.size(); i++) {
      Value value;
      Expression *expr;
      rc = Expression::create(nullptr, nullptr, nullptr, record_expr[i], expr, nullptr);
      if (rc != RC::SUCCESS) {
        LOG_WARN("fail to create expression in insert value");
        return rc;
      }
      rc = expr->try_get_value(value);
      delete expr;
      if (rc != RC::SUCCESS) {
        LOG_WARN("fail to get value in insert value");
        return rc;
      }
      record.push_back(value);
    }
    record_values.push_back(record);
  }

  stmt = new InsertStmt(table, record_values);
  return RC::SUCCESS;
}
