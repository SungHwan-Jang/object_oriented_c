//
// Created by redmk on 2021-01-17.
//

//
// Created by redmk on 2021-01-17.
//


#include "step2.h"
#if STEP2

int buf[16];
int top = 0;

static bool isStackFull(const Stack *p){
    return p->top == p->size;
}

static bool isStackEmpty(const Stack *p){
    return p->top == 0;
}

bool validateRange(Validator* pThis, int val){
    Range *pRange = (Range*)(pThis->pData);
    return pRange->max <= val && val <= pRange->max;
}

bool validatePrevious(Validator* pThis, int val){
    PreviousValue *pPrevious = (PreviousValue*)(pThis->pData);
    if(val < pPrevious->previousValue)
        return false;
    pPrevious->previousValue = val;
    return true;
}

bool validate(Validator *p, int val){
    if(!p)
        return true;
    return p->validate(p, val);
}

bool push(Stack *p, int val){
    if(!validate(p->pValidator, val) || isStackFull(p))
        return false;

    p->pBuf[p->top++] = val;
    return true;
}
bool pop(Stack *p, int *pRet){
    if(isStackEmpty(p))
        return false;

    *pRet = p->pBuf[--p->top];
    return true;
}

#endif
