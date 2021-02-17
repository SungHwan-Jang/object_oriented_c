#include <stdio.h>
#include "state_pattern.h"

int main() {
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

    return 0;
}
