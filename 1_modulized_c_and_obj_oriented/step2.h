//
// Created by redmk on 2021-01-17.
//

#ifndef INC_1_MODULIZED_C_AND_OBJ_ORIENTED_STEP2_H
#define INC_1_MODULIZED_C_AND_OBJ_ORIENTED_STEP2_H

#include "module.h"
#include "stdbool.h"
#include "stddef.h"

#if STEP2

typedef struct Validator{
    bool (*const validate)(struct Validator *pThis, int val);
    void * const pData;
}Validator;

typedef struct {
    const int min;
    const int max;
}Range;

typedef struct {
    int previousValue;
}PreviousValue;

typedef struct{
    int top;
    const size_t size;
    int* const pBuf;
    Validator * const pValidator;
}Stack;

bool validateRange(Validator* pThis, int val);
bool validatePrevious(Validator* pThis, int val);

bool push(Stack *p, int val);
bool pop(Stack *p, int *pRet);

#define newStack(buf) {0, sizeof(buf) / sizeof(int), (buf), NULL}
#define rangeValidator(pRange) {validateRange, pRange}
#define previousValidator(pPrevious) {validatePrevious, pPrevious}
#define newStackWithValidator(buf, pValidator) {0, sizeof(buf) / sizeof(int), (buf), pValidator}

#endif
#endif //INC_1_MODULIZED_C_AND_OBJ_ORIENTED_STEP1_H
