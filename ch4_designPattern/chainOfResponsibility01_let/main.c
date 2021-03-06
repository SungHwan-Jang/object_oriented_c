#include <stdio.h>
//#include "validator.h"
//#include "validate_diff_enhance.h"
#include "validate_diff_enhanced_stable.h"
#include "stdlib.h"
#include "time.h"

int main() {

    unsigned int randSeed = 0;
    initialize_ir_info_instance();
    srand(time(NULL));
    ir_in_ear_info info = IN_EAR_NONE_INFO;

#if 1
    int i =0;
    while (1){
        i++;
        scanf("%d", &randSeed);
        info = get_ir_ear_state(randSeed);
        if(info != IN_EAR_NONE_INFO){
            // get info state
            printf(" testcase : %d seed : %d // earState : %d [0-on / 1-off / 2-none]\n",
                   i,
                   randSeed,
                   info);
            printf("!!! IN_EAR STATE CHANGED !!! : %d\n", info);
        }
        else{
            //
            printf(" testcase : %d seed : %d // earState : %d [0-on / 1-off / 2-none]\n",
                   i,
                   randSeed,
                   info);
        }
    }
#endif
#if 0
    for(int i =0; i<20; i++){
        randSeed = rand() % 255;
        info = get_ir_ear_state(randSeed);
        if(info != IN_EAR_NONE_INFO){
            // get info state
            printf(" testcase : %d seed : %d // earState : %d [0-on / 1-off / 2-none]\n",
                   i,
                   randSeed,
                   info);
            printf("!!! IN_EAR STATE CHANGED !!! : %d\n", info);
        }
        else{
            //
            printf(" testcase : %d seed : %d // earState : %d [0-on / 1-off / 2-none]\n",
                   i,
                   randSeed,
                   info);
        }
    }
#endif

#if 0
// ring buffer test
    custom_ring_buffer_t testInstance = newCustomBuffer();
    unsigned int validateValue = 0;

    for(int i=0; i<0; i++){
        testInstance.push(&testInstance, i);
    }

    printf("test result is : %d\n", testInstance.pop(&testInstance));

    for(int i=0; i<0; i++){
        validateValue += i;
    }

    printf("test validate is : %d\n", (unsigned int)validateValue/0);
    return 0;
#endif
}
