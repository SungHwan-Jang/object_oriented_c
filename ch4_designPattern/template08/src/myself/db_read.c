//
// Created by redmk on 2021-03-01.
//
#include "limits.h"
#include "db_read.h"
#include "file_read.h"
#include "buf_control.h"
#include "stdlib.h"

// 1. buffer action -> create read_write fp for file read / qsort
//
/*
 * typedef struct {
    BufferContext base;
    Context *pAppCtx;
} MyBufferContext;

typedef struct {
    FileAccessorContext base;
    MyBufferContext *pBufCtx;
} MyFileAccessorContext;

typedef struct {
    FileAccessorContext base;
    long size;
} SizeGetterContext;
 * */

typedef struct {
    file_context_t base_file;
    buf_context_t base_buffer;
    context_t* pAppsCtx;
}sort_context_t;

typedef struct{
    file_context_t base;
    size_t size;
}size_getter_context_t;

err_type_t qsort_file(const char * fileName){
    return RET_OK;
}