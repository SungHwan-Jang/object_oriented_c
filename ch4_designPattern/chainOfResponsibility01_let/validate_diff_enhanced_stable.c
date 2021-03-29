//
// Created by admin on 2021-02-16.
//
#include "stdio.h"
#include "validate_diff_enhanced_stable.h"
#include "string.h"

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
        return;
    }
    else if(validate(irDetectInfo.pRangeValidate, &irDetectInfo) == true){
        printf("[   range detect  ]");
        printf("calib distance is : %d", irDetectInfo.bufInstance->pop(irDetectInfo.bufInstance));
        return;
    }
    else{
        printf("[reserved distance]");
        printf("calib distance is : %d", irDetectInfo.bufInstance->pop(irDetectInfo.bufInstance));
        return;
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

//FIXME : need calib max, min value ?
bool validateRange(Validator *p, void* obj){

    RangeValidator *validator = (RangeValidator *)p;
    ir_detect_info_t *info = (ir_detect_info_t*)obj;

    //updated previous distance.

    if(validator == NULL || info == NULL){
        return false;
    }

    if (info->currentDistance > validator->max) {
        printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
        info->earState = IN_EAR_ON_INFO;
        //info->bufInstance->reset(info->bufInstance);
        info->bufInstance->push(info->bufInstance, info->currentDistance);
        info->isAlarm = true;
        return true;
    }
    else if (info->currentDistance < validator->min) {
        printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
        info->earState = IN_EAR_OFF_INFO;
        //info->bufInstance->reset(info->bufInstance);
        info->bufInstance->push(info->bufInstance, info->currentDistance);
        info->isAlarm = true;
        return true;
    }
    else{
        info->isAlarm = false;
        return false;
    }
}

// check diff and reset distance.
bool validateDiff(Validator *p, void* obj){

    DiffentialValidator *validator = (DiffentialValidator *)p;
    ir_detect_info_t *info = (ir_detect_info_t*)obj;
    int diff = 0;


    if(validator == NULL || info == NULL){
        return false;
    }

    info->previousDistance = info->bufInstance->pop(info->bufInstance);
    diff = info->currentDistance - info->previousDistance;

    if(diff > validator->upperThr){ //IN_EAR_ON_INFO state
        printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
        info->earState = IN_EAR_ON_INFO;
        info->bufInstance->reset(info->bufInstance);
        info->bufInstance->push(info->bufInstance, info->currentDistance);

        info->isAlarm = true;
        return true;
    }
    else if(diff < -validator->upperThr){ // IN_EAR_OFF_INFO state
        printf("<distance CHANGE ! = before : %d , after : %d >\n", info->previousDistance, info->currentDistance);
        info->earState = IN_EAR_OFF_INFO;
        info->bufInstance->reset(info->bufInstance);
        info->bufInstance->push(info->bufInstance, info->currentDistance);

        info->isAlarm = true;
        return true;
    }
    else{
        // ignore state
        if (diff <= (int)validator->stableThr && diff >= (int)(-validator->stableThr)) { // calib previous distance
            info->bufInstance->push(info->bufInstance, info->currentDistance);
        }
        else {
            // force calib previous distance
            switch (info->earState) {
//                case IN_EAR_ON_INFO:
//                    if(diff > (int)(validator->stableThr)){
//                        //info->bufInstance->reset(info->bufInstance);
//                        info->bufInstance->push(info->bufInstance, info->currentDistance);
//                    }
//                    break;
                case IN_EAR_OFF_INFO:
                    if(diff < (int)(-validator->stableThr)){
                        info->bufInstance->reset(info->bufInstance);
                        info->bufInstance->push(info->bufInstance, info->currentDistance);
                    }
                    break;
                default:
                    break;
            }
        }

        info->isAlarm = false;
        return false;
    }
}