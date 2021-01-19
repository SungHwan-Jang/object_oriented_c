//
// Created by redmk on 2021-01-17.
//
#if STEP0

#include "regarcy_stack.h"
#include "stdio.h"


int buf[16];
int top = 0;

static bool isStackFull(void){
    return top == sizeof (buf) / sizeof (int);
}

static bool isStackEmpty(void){
    return top == 0;
}

bool push(int val){
    if(isStackFull())
        return false;

    buf[top++] = val;
    return true;
}
bool pop(int* pRef){
    if(isStackEmpty())
        return false;

    *pRef = buf[--top];
    return true;
}

#endif