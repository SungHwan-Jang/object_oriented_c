//
// Created by redmk on 2021-03-01.
//

#ifndef SRC_FILE_READ_H
#define SRC_FILE_READ_H
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct _file_t{
    const char* fileName;
    const char* mode;
    void (*processor)(struct _file_t* this, FILE* fp);
}file_t;

bool access_txt_file(file_t* ctx);

#endif //SRC_FILE_READ_H
