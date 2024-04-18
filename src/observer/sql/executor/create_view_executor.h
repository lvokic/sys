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
// Created by Wangyunlai on 2023/6/13.
//

#pragma once

#include "common/rc.h"
#include "common/log/log.h"
#include "session/session.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/stmt/create_view_stmt.h"
#include "storage/db/db.h"
#include "storage/table/view.h"

class SQLStageEvent;

/**
 * @brief 创建视图的执行器
 * @ingroup Executor
 */
class CreateViewExecutor
{
public:
  CreateViewExecutor() = default;
  virtual ~CreateViewExecutor() = default;

  RC execute(SQLStageEvent *sql_event)
  {
    RC rc = RC::SUCCESS;
    Stmt *stmt = sql_event->stmt();
    Session *session = sql_event->session_event()->session();
    ASSERT(stmt->type() == StmtType::CREATE_VIEW, 
            "create view executor can not run this command: %d", static_cast<int>(stmt->type()));

    CreateViewStmt *create_view_stmt = static_cast<CreateViewStmt*>(stmt);

    rc = session->get_current_db()->create_view(create_view_stmt->view_name().c_str(), create_view_stmt->allow_write(),
              create_view_stmt->attr_infos(), create_view_stmt->map_fields(), create_view_stmt->get_select_sql_node());
    if (RC::SUCCESS != rc) {
      LOG_WARN("failed to create view %s, rc=%s", create_view_stmt->view_name().c_str(), strrc(rc));
    }

    return rc;
  }
};