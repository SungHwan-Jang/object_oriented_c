#include <stdio.h>
#include <stdlib.h>
#include "module.h"

#if STEP0
#include "regarcy_stack.h"
#elif STEP1
#include "step1.h"
#elif STEP2
#include "step2.h"
#endif


int main() {
#if STEP0
    int i =0;
    int ret = 0;

    for(i=0; i<10; i++){
        push(i);
    }

    while(pop(&ret)){
        printf("ret is %d\n", ret);
    }
#endif

#if STEP1
    int temp1 = 0;
    int temp2 = 0;

    int buf[16];
    Stack stack1 = newStack(buf);

    int buf2[16];
    Stack stack2 = newStack(buf2);

    for(int i =0; i<10; i++){
        push(&stack1, i);
        push(&stack2, 50-i);
    }

    while (true){
        bool* resTmp1 = malloc(sizeof (bool));
        bool* resTmp2 = malloc(sizeof (bool));

        *resTmp1 = pop(&stack1, &temp1);
        *resTmp2 = pop(&stack2, &temp2);

        if(*resTmp1== false && *resTmp2== false){
            break;
        }
        printf("stack1 val is %d\n", temp1);
        printf("stack2 val is %d\n", temp2);

        free(resTmp1);
        free(resTmp2);
        resTmp1 = NULL;
        resTmp2 = NULL;
    }
#endif

#if STEP2

#endif
    return 0;
}
