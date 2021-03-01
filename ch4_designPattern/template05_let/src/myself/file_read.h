//
// Created by redmk on 2021-03-01.
//

#ifndef SRC_FILE_READ_H
#define SRC_FILE_READ_H
#include "stdio.h"
#include "stdlib.h"

typedef struct _file_context{
    const char* fileName;
    void (*processor)(struct _file_context* this, FILE* fp);
}file_context_t;

int read_txt_file(file_context_t* ctx);

#endif //SRC_FILE_READ_H
