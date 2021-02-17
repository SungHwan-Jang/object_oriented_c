#include "stdio.h"
#include "validator.h"
#include "stdlib.h"
#include "time.h"

int main() {

    unsigned int randSeed = 0;
    initialize_ir_info_instance();
    srand(time(NULL));
    ir_in_ear_info info = IN_EAR_NONE_INFO;

    for(int i =0; i<100; i++){
        randSeed = rand() % 255;
        info = get_ir_ear_state(randSeed);
        if(info != IN_EAR_NONE_INFO){
            printf(" testcase : %d seed : %d // earState : %d [0-on / 1-off / 2-none]\n",
                   i,
                   randSeed,
                   info);
        }
        else{
            printf("reseved testcase : %d seed : %d // earState : %d [0-on / 1-off / 2-none]\n",
                   i,
                   randSeed,
                   info);
        }
    }

    return 0;
}
