//
// Created by redmk on 2021-03-02.
//

#ifndef SRC_BUF_CONTROL_H
#define SRC_BUF_CONTROL_H
#include "stdbool.h"
#include "stdlib.h"

typedef struct _buf_t{
    void* pBuf;
    size_t size;
    void (* const buf_control)(struct _buf_t* this);
}buf_t;

bool new_buffer(buf_t* this);

#endif //SRC_BUF_CONTROL_H
