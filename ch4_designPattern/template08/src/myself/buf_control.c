//
// Created by redmk on 2021-03-02.
//

#include "buf_control.h"

bool new_buffer(buf_context_t* this){
    this->pBuf = malloc(this->size);
    if(this->pBuf == NULL)
        return false;

    this->buf_control(this);
    free(this->pBuf);

    return true;
}
