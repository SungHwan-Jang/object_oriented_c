//
// Created by redmk on 2021-02-27.
//

#ifndef CD3_STATEPATTERN_LET_SELF_STATE_H
#define CD3_STATEPATTERN_LET_SELF_STATE_H

typedef struct _state{
    const struct _state *(*insert_cd)(const struct _state *this);
    const struct _state *(*remove_cd)(const struct _state *this);
    const struct _state *(*stop)(const struct _state *this);
    const struct _state *(*play_pause)(const struct _state *this);
}STATE_t;

/* public method */
void init();
void insert_disk();
void remove_disk();
void stop();
void play_pause();


#endif //CD3_STATEPATTERN_LET_SELF_STATE_H
