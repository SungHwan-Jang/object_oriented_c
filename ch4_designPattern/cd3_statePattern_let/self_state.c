//
// Created by redmk on 2021-02-27.
//

#include "self_state.h"
#include <stdio.h>

static const STATE_t * currentState;

static const STATE_t *idle_on(const STATE_t *this);
static const STATE_t *idle_off(const STATE_t *this);
static const STATE_t *start_play(const STATE_t *this);
static const STATE_t *pause_play(const STATE_t *this);
static const STATE_t *resume_play(const STATE_t *this);
static const STATE_t *stop_play(const STATE_t *this);
static const STATE_t *ignore(const STATE_t *this);

/*
 *
typedef struct _state{
    const struct _state *(*insert_cd)(const struct _state *this);
    const struct _state *(*remove_cd)(const struct _state *this);
    const struct _state *(*stop)(const struct _state *this);
    const struct _state *(*play_pause)(const struct _state *this);
}STATE_t;

 */
const STATE_t STATE_IDLE_ON = {
        ignore,
        idle_off,
        ignore,
        start_play,
};

const STATE_t STATE_IDLE_OFF = {
        idle_on,
        ignore,
        ignore,
        ignore,
};

const STATE_t STATE_PLAY = {
        ignore,
        ignore,
        stop_play,
        pause_play,
};

const STATE_t STATE_PAUSE = {
        ignore,
        ignore,
        stop_play,
        resume_play,
};

static const STATE_t *idle_on(const STATE_t *this) {
    printf("idle on state");
    return &STATE_IDLE_ON;
}

static const STATE_t *idle_off(const STATE_t *this) {
    printf("idle off state");
    return &STATE_IDLE_OFF;
}

static const STATE_t *start_play(const STATE_t *this) {
    printf("play music");
    return &STATE_PLAY;
}

static const STATE_t *pause_play(const STATE_t *this) {
    printf("pause music");
    return &STATE_PAUSE;
}

static const STATE_t *resume_play(const STATE_t *this) {
    printf("resume music");
    return &STATE_PLAY;
}

static const STATE_t *stop_play(const STATE_t *this) {
    printf("stop music");
    return &STATE_IDLE_ON;
}

static const STATE_t *ignore(const STATE_t *this) {
    printf("--");
    return currentState;
}

/* public method */

void init(){
    currentState = &STATE_IDLE_OFF;
}

void insert_disk(){
    currentState = currentState->insert_cd(currentState);
}

void remove_disk(){
    currentState = currentState->remove_cd(currentState);
}

void stop(){
    currentState = currentState->stop(currentState);
}

void play_pause(){
    currentState = currentState->play_pause(currentState);
}