//
// Created by redmk on 2021-03-01.
//
#include <stdio.h>
#include "range.h"
#include "file_reader.h"

int main(void){
    const char* fileName = "test.txt";
    int ret = range(fileName);

    printf("ret is %d\n", ret);

    return 0;
}