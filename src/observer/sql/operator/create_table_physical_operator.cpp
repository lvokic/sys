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

#include "common/log/log.h"
#include "storage/trx/trx.h"
#include "storage/table/table.h"
#include "storage/record/record.h"
#include "sql/operator/create_table_physical_operator.h"

RC CreateTablePhysicalOperator::open(Trx *trx)
{
  RC rc = RC::SUCCESS;

  if (!children_.empty()) {
    std::unique_ptr<PhysicalOperator> &child = children_[0];
    rc = child->open(trx);
    if (RC::SUCCESS != rc) {
      LOG_WARN("failed to open child oper, rc=%s", strrc(rc));
      return rc;
    }
  }

  const int attr_count = attr_infos_.size();
  rc = db_->create_table(table_name_.c_str(), attr_count, attr_infos_.data());
  if (RC::SUCCESS != rc) {
    LOG_WARN("failed to create table %s, rc=%s", table_name_.c_str(), strrc(rc));
    return rc;
  }

  if (!children_.empty()) {
    Table *table = db_->find_table(table_name_.c_str());
    if (nullptr == table) {
      // unexpected error
      LOG_ERROR("failed to find table %s", table_name_.c_str());
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    std::unique_ptr<PhysicalOperator> &child = children_[0];

    while (RC::SUCCESS == (rc = child->next())) {
      Tuple *tuple = child->current_tuple();
      if (nullptr == tuple) {
        LOG_WARN("failed to get current record, rc=%s", strrc(rc));
        return rc;
      }
      Record record;
      std::vector<Value> values(tuple->cell_num());
      for (int i = 0; i < tuple->cell_num(); i++) {
        tuple->cell_at(i, values[i]);
      }

      rc = table->make_record(values.size(), values.data(), record);
      if(RC::SUCCESS != rc) {
        LOG_WARN("failed to make record, rc=%s", strrc(rc));
        return rc;
      }

      rc = trx->insert_record(table, record);
      if (RC::SUCCESS != rc) {
        LOG_WARN("failed to insert record into, rc=%s", strrc(rc));

        RC rc2 = db_->drop_table(table_name_.c_str());
        if (RC::SUCCESS != rc2) {
          LOG_WARN("failed to drop table after insert failed, rc=%s", strrc(rc2));
        }
        return rc;
      }
    }
    if (RC::RECORD_EOF == rc) rc = RC::SUCCESS;
  }
  return rc;
}

RC CreateTablePhysicalOperator::next()
{
  return RC::RECORD_EOF;
}

RC CreateTablePhysicalOperator::close()
{
  RC rc = RC::SUCCESS;
  if (!children_.empty()) {
    rc = children_[0]->close();
    if (RC::SUCCESS != rc) {
      LOG_WARN("failed to close child_oper, rc= %s", strrc(rc));
    }
  }
  return rc;
}

Tuple *CreateTablePhysicalOperator::current_tuple()
{
  return nullptr;
}