//
// Created by admin on 2021-02-16.
//
#include "stdio.h"
#include "validate_diff_enhance.h"
#include "string.h"
#include "math.h"

static custom_ring_buffer_t buffInstance;
static DiffentialValidator diffValidator = newDiffValidator();
static RangeValidator rangeValidator = newRangeValidator();
static ir_detect_info_t irDetectInfo;

static bool validate(Validator *p, void* obj){
    if(!p){
        return true;
    }
    return p->check(p, obj);
}

static bool get_ir_detect_alarm(void){
    bool ret = irDetectInfo.isAlarm;
    irDetectInfo.isAlarm = false;
    return ret;
}

static void update_ir_detect_info(unsigned int curDistance){

    irDetectInfo.currentDistance = curDistance;

    if(validate(irDetectInfo.pDiffValidate, &irDetectInfo) == true){
        printf("[   diff detect  ]");
    }
    else if(validate(irDetectInfo.pRangeValidate, &irDetectInfo) == true){
        printf("[   range detect  ]");
    }
    else{
        printf("[reserved distance]");
    }
}

void initialize_ir_info_instance(void){

    custom_ring_buffer_t tmpBuff = newCustomBuffer();

    for(int i =0; i<RING_BUFFER_MAX; i++)
        tmpBuff.push(&tmpBuff, IR_DETECT_MIN_THRESHOLD);

    memcpy(&buffInstance, &tmpBuff, sizeof (custom_ring_buffer_t));

    ir_detect_info_t tmpInfo = newIrDetectInfo(&buffInstance,&rangeValidator.this, &diffValidator.this);
    memcpy(&irDetectInfo, &tmpInfo, sizeof (ir_detect_info_t));
}

/* public function */
ir_in_ear_info get_ir_ear_state(unsigned int curDistance){

    update_ir_detect_info(curDistance);

    if(get_ir_detect_alarm() == true){
        return irDetectInfo.earState;
    }
    else{
        return IN_EAR_NONE_INFO;
    }
}

void insert_ring_buffer (struct _custom_ring_buffer *pThis, const unsigned int curDistance){

    if(pThis->idx >= RING_BUFFER_MAX){
        pThis->maxFlag = true;
        pThis->idx = 0;
    }

    pThis->buf[pThis->idx] = curDistance;
    pThis->idx++;
}

unsigned int get_average_ring_buffer (struct _custom_ring_buffer *pThis){

    unsigned int total = 0;
    unsigned int ret = 0;

    if(pThis->maxFlag != true){
        if(pThis->idx == 0)
            return 0;

        for(int i=0; i < pThis->idx; i++){
            total+=pThis->buf[i];
        }
        ret = total/pThis->idx;
    }
    else{
        for(int i=0; i < RING_BUFFER_MAX; i++){
            total+=pThis->buf[i];
        }
        ret = total/RING_BUFFER_MAX;
    }
    return ret;
}

void reset_buffer (struct _custom_ring_buffer *pThis){

    memset(pThis->buf, 0, sizeof (unsigned int) * RING_BUFFER_MAX);
    pThis->idx = 0;
    pThis->maxFlag = false;
}

bool validateRange(Validator *p, void* obj){

    RangeValidator *validator = (RangeValidator *)p;
    ir_detect_info_t *info = (ir_detect_info_t*)obj;

    if(validator == NULL || info == NULL){
        return false;
    }

#if 0
    if(info->currentDistance > validator->max){

        if(info->earState != IN_EAR_ON_INFO){
            printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
            info->earState = IN_EAR_ON_INFO;
            info->previousDistance = info->currentDistance;
            info->isAlarm = true;
        }
        else{
            if(info->currentDistance > info->previousDistance) {
                printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance,
                       info->currentDistance);
                info->previousDistance = info->currentDistance;
            }
            info->isAlarm = false;
        }


        return true;
    }
    else if(info->currentDistance < validator->min){

        if(info->earState != IN_EAR_OFF_INFO){
            printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
            info->earState = IN_EAR_OFF_INFO;
            info->previousDistance = info->currentDistance;
            info->isAlarm = true;
        }
        else{
            if(info->currentDistance < info->previousDistance){
                printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
                info->previousDistance = info->currentDistance;
            }

            info->isAlarm = false;
        }

        return true;
    }
    else{
        return false;
    }
#endif
}

bool validateDiff(Validator *p, void* obj){

    DiffentialValidator *validator = (DiffentialValidator *)p;
    ir_detect_info_t *info = (ir_detect_info_t*)obj;

    if(validator == NULL || info == NULL){
        return false;
    }

    int diff = (info->currentDistance - info->bufInstance->pop(info->bufInstance));

    if(diff > validator->upperThr){ //IN_EAR_ON_INFO state
        printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
        info->earState = IN_EAR_ON_INFO;
        info->previousDistance = info->currentDistance;
        info->isAlarm = true;
        return true;
    }
    else if(diff < -(validator->upperThr)){ // IN_EAR_OFF_INFO state
        printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
        info->earState = IN_EAR_OFF_INFO;
        info->previousDistance = info->currentDistance;
        info->isAlarm = true;
        return true;
    }
    else{
        // ignore state
    }

    info->bufInstance->push(info->bufInstance, info->currentDistance);

#if 0
    int diff = info->currentDistance - info->previousDistance;

    if(diff > validator->diff){
        printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
        info->earState = IN_EAR_ON_INFO;
        info->previousDistance = info->currentDistance;
        info->isAlarm = true;
        return true;
    }
    else if(diff < -(validator->diff)){
        printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
        info->earState = IN_EAR_OFF_INFO;
        info->previousDistance = info->currentDistance;
        info->isAlarm = true;
        return true;
    }
    else{
        return false;
    }
#endif
}