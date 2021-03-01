//
// Created by redmk on 2021-03-01.
//

#include <stdio.h>
#include "range.h"
#include <stdlib.h>

int main(void){
    int ret;
#if 0
    /* it make output folder (cmake-build-debug) */
    FILE *fp = fopen("test.txt", "w");
    fputs("1231\n", fp);
    fputs("1\n", fp);
    fputs("441\n", fp);

    fclose(fp);
#endif

    ret = range("test.txt");
    printf("ret is : %d", ret);
    return 0;
}