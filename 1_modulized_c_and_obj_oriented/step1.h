//
// Created by redmk on 2021-01-17.
//

#ifndef INC_1_MODULIZED_C_AND_OBJ_ORIENTED_STEP1_H
#define INC_1_MODULIZED_C_AND_OBJ_ORIENTED_STEP1_H


#include "module.h"
#include "stdbool.h"
#include "stddef.h"

#if STEP1

#define newStack(buf) {\
    0, sizeof(buf) / sizeof(int), (buf)\
    }

typedef struct{
    int top;
    const size_t size;
    int* const pBuf;
}Stack;

bool push(Stack *p, int val);
bool pop(Stack *p, int *pRet);

#endif
#endif //INC_1_MODULIZED_C_AND_OBJ_ORIENTED_STEP1_H
