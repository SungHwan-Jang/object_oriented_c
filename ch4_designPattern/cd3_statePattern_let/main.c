#include <stdio.h>
#if 0
#include "state_pattern.h"
#else
#include "self_state.h"
#endif
int main() {

#if 0
    char* currentState;

    printf("Hello, World!\n");

    initialize();

    onPlayOrPause();

    currentState = get_current_state();

    printf("current state : %s\n", currentState);

    onPlayOrPause();

    currentState = get_current_state();

    printf("current state : %s\n", currentState);

    onStop();

    currentState = get_current_state();

    printf("current state : %s\n", currentState);

    onStop();

    currentState = get_current_state();

    printf("current state : %s\n", currentState);
#else
    int cmd = 0;
    init();

    while(1){
        printf("cmd list : 1 - insert / 2 - remove / 3 - p/p / 4 - stop");
        scanf("%d", &cmd);

        switch (cmd) {
            case 1:
                insert_disk();
                break;
            case 2:
                remove_disk();
                break;
            case 3:
                play_pause();
                break;
            case 4:
                stop();
                break;
            default:

                break;
        }
    }
#endif
    return 0;
}
