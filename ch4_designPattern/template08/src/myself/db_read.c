//
// Created by redmk on 2021-03-01.
//
#include "limits.h"
#include "db_read.h"
#include "file_read.h"
#include "buf_control.h"
#include "stdlib.h"
#include "string.h"

// 1. buffer action -> create read_write fp for file read / qsort

typedef struct {
    buf_t base;
    qsort_context_t* ctx;
}buffer_ctx_t;

typedef struct {
    file_t base;
    buffer_ctx_t *bufferCtx;
}file_access_ctx_t;

typedef struct{
    file_t base;
    size_t size;
}size_getter_context_t;

static long _get_size(char * const fileName);
static void _read_file_size(struct _file_t* this, FILE* fp);
static void _qsort_action(struct _buf_t* this);
static void _reader(struct _file_t* this, FILE* fp);
static void _writer(struct _file_t* this, FILE* fp);
static int _comparator(const void *p1, const void *p2);

err_type_t qsort_file(char * const fileName){
    qsort_context_t ctx = {fileName, RET_OK};
    long size = _get_size(fileName);

    if(size == -1){
        fprintf(stderr, "%s : %s\n", ctx.fileName, strerror(errno));
        ctx.errType = RET_FILE_ACCESS_FAIL;
    }

    buffer_ctx_t bufferCtx = {{NULL, size, _qsort_action}, &ctx};

    if(new_buffer(&bufferCtx.base) == false)
    {

    }

    return ctx.errType;
}

static long _get_size(char * const fileName){
    file_t fileInfo = {fileName, "rb", _read_file_size};
    size_getter_context_t ctx = {fileInfo, 0};

    if(!access_txt_file(&ctx.base)){
        return -1;
    }

    return ctx.size;
}

static void _read_file_size(struct _file_t* this, FILE* fp){
    size_getter_context_t *sizeGetterContext = (size_getter_context_t *)this;
    sizeGetterContext->size = -1;

    if(fseek(fp, 0, SEEK_END) == 0)
        sizeGetterContext->size = ftell(fp);
}

static void _qsort_action(struct _buf_t* this){
    buffer_ctx_t * bufferCtx = (buffer_ctx_t*)this;
    file_access_ctx_t fileReaderAccessCtx = {{bufferCtx->ctx->fileName, "rb", _reader}, bufferCtx};

    if(!access_txt_file(&fileReaderAccessCtx.base)){
        fprintf(stderr, "%s : %s\n", bufferCtx->ctx->fileName, strerror(errno));
        bufferCtx->ctx->errType = RET_FILE_ACCESS_FAIL;
        return;
    }
    qsort(bufferCtx->base.pBuf, bufferCtx->base.size / sizeof (int), sizeof (int), _comparator);

    file_access_ctx_t fileWriterAccessCtx = {{bufferCtx->ctx->fileName, "wb", _writer}, bufferCtx};

    if(!access_txt_file(&fileWriterAccessCtx.base)){
        fprintf(stderr, "%s : %s\n", bufferCtx->ctx->fileName, strerror(errno));
        bufferCtx->ctx->errType = RET_FILE_ACCESS_FAIL;
        return;
    }
}

static void _reader(struct _file_t* this, FILE* fp){
    file_access_ctx_t* fileAccessCtx = (file_access_ctx_t*)this;
    buffer_ctx_t* bufferCtx = fileAccessCtx->bufferCtx;

    if(bufferCtx->base.size != fread(bufferCtx->base.pBuf, sizeof(char), bufferCtx->base.size, fp)){
        fprintf(stderr, "%s : %s\n", bufferCtx->ctx->fileName, strerror(errno));
        bufferCtx->ctx->errType = RET_FILE_ACCESS_FAIL;
    }
}

static void _writer(struct _file_t* this, FILE* fp) {
    file_access_ctx_t* fileAccessCtx = (file_access_ctx_t*)this;
    buffer_ctx_t* bufferCtx = fileAccessCtx->bufferCtx;

    if(bufferCtx->base.size != fwrite(bufferCtx->base.pBuf, sizeof(char), bufferCtx->base.size, fp)){
        fprintf(stderr, "%s : %s\n", bufferCtx->ctx->fileName, strerror(errno));
        bufferCtx->ctx->errType = RET_FILE_ACCESS_FAIL;
    }
}


static int _comparator(const void *p1, const void *p2) {
    int i1 = *(const int *)p1;
    int i2 = *(const int *)p2;
    if (i1 < i2) return -1;
    if (i1 > i2) return 1;
    return 0;
}