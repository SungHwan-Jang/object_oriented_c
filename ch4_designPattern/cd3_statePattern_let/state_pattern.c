//
// Created by redmk on 2021-02-17.
//
#include "state_pattern.h"
#include <stdbool.h>

static const State *pCurrentState;

static const State *ignore(const State *pThis);
static const State *startPlay(const State *pThis);
static const State *stopPlay(const State *pThis);
static const State *pausePlay(const State *pThis);
static const State *resumePlay(const State *pThis);

const State IDLE = {
        "IDLE",
        ignore,
        startPlay
};

const State PLAY = {
        "PLAY",
        stopPlay,
        pausePlay
};

const State PAUSE = {
        "PAUSE",
        stopPlay,
        resumePlay
};

void initialize() {
    pCurrentState = &IDLE;
}

char* get_current_state(){
    return pCurrentState->stateName;
}

void onStop() {
    pCurrentState = pCurrentState->stop(pCurrentState);
}

void onPlayOrPause() {
    pCurrentState = pCurrentState->playOrPause(pCurrentState);
}

static const State *ignore(const State *pThis) {
    return pCurrentState;
}

static const State *stopPlay(const State *pThis) {
    return &IDLE;
}

static const State *pausePlay(const State *pThis) {
    return &PAUSE;
}

static const State *resumePlay(const State *pThis) {
    return &PLAY;
}

static const State *startPlay(const State *pThis) {
    return &PLAY;
}