//
// Created by redmk on 2021-03-01.
//

#ifndef SRC_DB_READ_H
#define SRC_DB_READ_H

#include "file_read.h"

typedef struct _db_context{
    file_context_t base;
    int average;
}db_context_t;

int get_average(const char* fileName);

#endif //SRC_DB_READ_H
