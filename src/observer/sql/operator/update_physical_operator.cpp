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

#include "sql/operator/update_physical_operator.h"
#include "common/global_context.h"
#include "common/log/log.h"
#include "common/rc.h"
#include "event/sql_debug.h"
#include "sql/expr/tuple.h"
#include "sql/parser/value.h"
#include "storage/default/default_handler.h"
#include "storage/trx/trx.h"
#include <cassert>
#include <cstring>

using namespace std;

#define line_sql_debug(fmt, ...) sql_debug(__FILE__ ":%d" fmt, __LINE__, __VA_ARGS__)

RC UpdatePhysicalOperator::open(Trx *trx) {
    RC rc = children_[0]->open(trx);
    if (rc != RC::SUCCESS) 
        return rc;
    vector<vector<Value>> value_list;
    while ((rc = children_[0]->next()) == RC::SUCCESS) {
        Record *record;
        Tuple *tuple = children_[0]->current_tuple();
        rc = tuple->get_record(table_, record);
        if (rc != RC::SUCCESS) {
            line_sql_debug("rc=%s", strrc(rc));
            return rc;
        }
        vector<char> r(table_->table_meta().record_size());
        memcpy(r.data(), record->data(), r.size());
        rc = trx_->delete_record(table_, *record);
        if (rc != RC::SUCCESS) {
            line_sql_debug("rc=%s", strrc(rc));
            return rc;
        }
        deleted_records_.push_back(r);
        vector<Value> values;
        for (auto &unit : units_) {
            Value value;
            rc = unit.value->get_value(*tuple, value);
            if (rc != RC::SUCCESS) {
                line_sql_debug("rc=%s", strrc(rc));
                return rc;
            }
            values.push_back(value);
        }
        value_list.push_back(values);
    }
    children_[0]->close();
    if (rc != RC::RECORD_EOF) {
        line_sql_debug("rc=%s", strrc(rc));
        return rc;
    }
    for (int i = 0; i < deleted_records_.size(); i++) {
        RID rid;
        rc = update(deleted_records_[i], value_list[i], rid);
        if (rc != RC::SUCCESS) {
            line_sql_debug("rc=%s", strrc(rc));
            return rc;
        }
        inserted_records_.push_back(rid);
    }
    return RC::SUCCESS;
}

RC UpdatePhysicalOperator::insert_all(vector<vector<char>> &v) {
    RC rc_ret = RC::SUCCESS;
    for (auto &x : v) {
        RID rid;
        RC rc = insert(x, rid);
        if (rc != RC::SUCCESS) {
            LOG_ERROR("fail to insert all");
            if (rc_ret == RC::SUCCESS) {
                rc_ret = rc;
            }
        }
    }
    return rc_ret;
}

RC UpdatePhysicalOperator::insert(vector<char> &v, RID &rid) {
    Record record;
    RC rc = table_->make_record(v.data(), v.size(), record);
    if (rc != RC::SUCCESS) {
        line_sql_debug("rc=%s", strrc(rc));
        LOG_ERROR("fail to make record");
        return rc;
    }
    rc = trx_->insert_record(table_, record);
    if (rc != RC::SUCCESS) {
        line_sql_debug("rc=%s", strrc(rc));
        LOG_ERROR("fail to insert record");
        return rc;
    }
    rid = record.rid();
    return rc;
}

RC UpdatePhysicalOperator::remove_all(const vector<RID> &rids) {
  RC rc_ret = RC::SUCCESS;
  for (auto &rid : rids) {
    RC rc = trx_->delete_record(table_, rid);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("fail to delete record");
      if (rc_ret == RC::SUCCESS) {
        rc_ret = rc;
      }
    }
  }
  return rc_ret;
}

RC UpdatePhysicalOperator::update(vector<char> v, vector<Value> &values, RID &rid) {
    RC rc = RC::SUCCESS;
    for (int i = 0; i < values.size(); i++) {
        auto &unit = units_[i];
        Value value;
        const auto *meta = unit.field.meta();
        if (value.attr_type() != meta->type()) {
            if (!Value::convert(value.attr_type(), meta->type(), value)) {
                line_sql_debug("rc=%s", strrc(RC::INVALID_ARGUMENT));
                LOG_WARN("failed to convert update value");
                return RC::INVALID_ARGUMENT;
            }
        }
        int offset = meta->offset();
        if (meta->type() != CHARS) {
            memcpy(v.data() + offset, value.data(), value.length());
        } else {
            memcpy(v.data() + offset, value.data(), value.length());
            memset(v.data() + offset + value.length(), 0, meta->len() - value.length());
        }
        return insert(v, rid);
    }
}

void UpdatePhysicalOperator::rollback() {
  remove_all(inserted_records_);
  insert_all(deleted_records_);
}
