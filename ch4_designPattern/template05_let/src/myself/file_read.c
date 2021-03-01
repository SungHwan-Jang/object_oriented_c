//
// Created by redmk on 2021-03-01.
//

#include "file_read.h"
#include "stdio.h"

int read_txt_file(file_context_t* ctx){
    FILE *fp = fopen(ctx->fileName, "r");
    ctx->processor(ctx, fp);
    fclose(fp);
}