//
// Created by redmk on 2021-03-01.
//

#ifndef SRC_DB_READ_H
#define SRC_DB_READ_H

#include "file_read.h"

typedef enum{
    RET_OK,
    RET_MEM_FAIL,
    RET_FILE_ACCESS_FAIL,
}err_type_t;

typedef struct qsort_context_t{
    char * const fileName;
    err_type_t errType;
}qsort_context_t;

err_type_t qsort_file(char * const fileName);
#endif //SRC_DB_READ_H
