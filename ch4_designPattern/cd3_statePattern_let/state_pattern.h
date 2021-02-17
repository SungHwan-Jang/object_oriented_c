//
// Created by redmk on 2021-02-17.
//

#ifndef CD3_STATEPATTERN_LET_STATE_PATTERN_H
#define CD3_STATEPATTERN_LET_STATE_PATTERN_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _State {
    char* stateName;
    const struct _State *(*stop)(const struct _State *pThis);
    const struct _State *(*playOrPause)(const struct _State *This);
} State;

void initialize();
char* get_current_state();
void onStop();
void onPlayOrPause();


#ifdef __cplusplus
}
#endif

#endif //CD3_STATEPATTERN_LET_STATE_PATTERN_H
