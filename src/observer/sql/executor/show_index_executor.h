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

#pragma once

#include "common/rc.h"
#include "common/log/log.h"
#include "session/session.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "sql/executor/sql_result.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "storage/index/index.h"
#include "sql/stmt/show_index_stmt.h"
#include "sql/operator/string_list_physical_operator.h"

class SQLStageEvent;

/**
 * @brief 展示索引的执行器
 * @ingroup Executor
 */
class ShowIndexExecutor
{
public:
  ShowIndexExecutor() = default;
  virtual ~ShowIndexExecutor() = default;

  RC execute(SQLStageEvent *sql_event)
  {
    RC rc = RC::SUCCESS;
    Stmt *stmt = sql_event->stmt();
    Session *session = sql_event->session_event()->session();
    ASSERT(stmt->type() == StmtType::SHOW_INDEX, 
          "show index executor can not run this command: %d", static_cast<int>(stmt->type()));

    Db *db = session->get_current_db();
    SqlResult *sql_result = sql_event->session_event()->sql_result();

    ShowIndexStmt *show_index_stmt = static_cast<ShowIndexStmt *>(stmt);
    const char *table_name = show_index_stmt->table_name().c_str();    
    Table *table = db->find_table(table_name);
    if (nullptr != table) {
      // 设置表头
      TupleSchema tuple_schema;
      tuple_schema.append_cell(TupleCellSpec("", "Table", "Table"));
      tuple_schema.append_cell(TupleCellSpec("", "Non_unique", "Non_unique"));
      tuple_schema.append_cell(TupleCellSpec("", "Key_name", "Key_name"));
      tuple_schema.append_cell(TupleCellSpec("", "Seq_in_index", "Seq_in_index"));
      tuple_schema.append_cell(TupleCellSpec("", "Column_name", "Column_name"));
      sql_result->set_tuple_schema(tuple_schema);

      // TODO: 唯一索引、多列索引等情况
      auto oper = new StringListPhysicalOperator;
      std::vector<IndexMeta> indexes = table->table_meta().indexes();
      for (size_t i = 0; i < indexes.size(); i++) {
        for (size_t j = 1; j < indexes[i].fields().size(); j++) {
          oper->append({table->name(),                      // Table
                        indexes[i].unique() ? "0" :"1",  // Unique
                        indexes[i].name(),    // Key_name
                        to_string(j),                     // Seq_in_index
                        indexes[i].fields().at(j).name()}); // Column_name
        }
      }
      sql_result->set_operator(std::unique_ptr<PhysicalOperator>(oper));
    } else {
      rc = RC::SCHEMA_TABLE_NOT_EXIST;
      sql_result->set_return_code(rc);
      sql_result->set_state_string("Table not exists");
    }

    return rc;
  }
};