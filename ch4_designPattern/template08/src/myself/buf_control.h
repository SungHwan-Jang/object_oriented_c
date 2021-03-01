//
// Created by redmk on 2021-03-02.
//

#ifndef SRC_BUF_CONTROL_H
#define SRC_BUF_CONTROL_H
#include "stdbool.h"
#include "stdlib.h"

typedef struct buf_context{
    void* pBuf;
    size_t size;
    void (* const buf_control)(struct buf_context* this);
}buf_context_t;

bool new_buffer(buf_context_t* buf);

#endif //SRC_BUF_CONTROL_H
