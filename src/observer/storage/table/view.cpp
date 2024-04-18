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

#include <fstream>
#include <fcntl.h>
#include <common/lang/string.h>

#include "json/json.h"
#include "common/log/log.h"
#include "sql/parser/parse.h"
#include "storage/table/view.h"
#include "storage/field/field.h"
#include "storage/field/field_meta.h"

RC View::create(int32_t table_id, 
                bool allow_write, 
                const char *path,       // .view文件路径、名称
                const char *name,       // view_name
                const char *base_dir,   // db/sys
                const std::vector<AttrInfoSqlNode> &attr_infos, 
                const std::vector<Field> &map_fields, 
                SelectSqlNode *select_sql)
{
  RC rc = RC::SUCCESS;
  if (table_id < 0) {
    LOG_WARN("invalid table id. table_id=%d, view_name=%s", table_id, name);
    return RC::INVALID_ARGUMENT;
  }
  if (common::is_blank(name)) {
    LOG_WARN("Name cannot be empty");
    return RC::INVALID_ARGUMENT;
  }
  if (attr_infos.size() <= 0) {
    LOG_WARN("Invalid arguments. view_name=%s, attribute_count=%d", name, attr_infos.size());
    return RC::INVALID_ARGUMENT;
  }

  LOG_INFO("Begin to create view %s:%s", base_dir, name);
  set_view_type();
  allow_write_ = allow_write;
  map_fields_ = map_fields;
  select_sql_.deep_copy(*select_sql);
  if ((rc = table_meta_.init(table_id, name, attr_infos.size(), attr_infos.data())) != RC::SUCCESS) {
    LOG_ERROR("Failed to init table meta. name:%s, ret:%d", name, rc);
    return rc;  // delete table file
  }

  // 使用 name.view记录一个视图的元数据，判断视图文件是否已经存在
  int fd = ::open(path, O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
  if (fd < 0) {
    if (EEXIST == errno) {
      LOG_ERROR("Failed to create table file, it has been created. %s, EEXIST, %s", path, strerror(errno));
      return RC::SCHEMA_TABLE_EXIST;
    }
    LOG_ERROR("Create table file failed. filename=%s, errmsg=%d:%s", path, errno, strerror(errno));
    return RC::IOERR_OPEN;
  }
  close(fd);

  // 记录元数据到文件中
  std::fstream fs;
  fs.open(path, std::ios_base::out | std::ios_base::binary);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open file for write. file name=%s, errmsg=%s", path, strerror(errno));
    return RC::IOERR_OPEN;
  }
  table_meta_.serialize(fs);
  fs.close();

  return rc;
}

RC View::open()
{
  RC rc = RC::SUCCESS;

  return rc;
}

RC View::drop()
{
  RC rc = RC::SUCCESS;

  return rc;
}

RC View::serialize(std::fstream &fs)
{
  RC rc = RC::SUCCESS;

  return rc;
}

RC View::deserialize()
{
  RC rc = RC::SUCCESS;

  return rc;
}