//
// Created by redmk on 2021-03-01.
//

#include "file_read.h"
#include "stdio.h"

bool access_txt_file(file_t* ctx){
    FILE *fp = fopen(ctx->fileName, ctx->mode);
    if(fp == NULL)
        return false;

    ctx->processor(ctx, fp);
    fclose(fp);

    return true;
}