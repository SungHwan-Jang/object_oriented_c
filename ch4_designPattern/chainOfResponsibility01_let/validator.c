//
// Created by admin on 2021-02-16.
//
#if 0
#include "stdio.h"
#include "validator.h"
#include "string.h"
#include "math.h"

static PreviousValueValidator diffValidator = newDiffValidator();
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

    if(validate(irDetectInfo.pRangeValidate, &irDetectInfo) == true){
        printf("[   range detect  ]");
    }
    else if(validate(irDetectInfo.pDiffValidate, &irDetectInfo) == true){
        printf("[   diff detect  ]");
    }
    else{
        printf("[reserved distance]");
    }
}

void initialize_ir_info_instance(void){
    ir_detect_info_t tmp = newIrDetectInfo(&rangeValidator.this, &diffValidator.this);
    memcpy(&irDetectInfo, &tmp, sizeof (ir_detect_info_t));
}

ir_in_ear_info get_ir_ear_state(unsigned int curDistance){

    update_ir_detect_info(curDistance);

    if(get_ir_detect_alarm() == true){
        return irDetectInfo.earState;
    }
    else{
        return IN_EAR_NONE_INFO;
    }
}

bool validateRange(Validator *p, void* obj){

    RangeValidator *validator = (RangeValidator *)p;
    ir_detect_info_t *info = (ir_detect_info_t*)obj;

    if(validator == NULL || info == NULL){
        return false;
    }

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
}

bool validateDiff(Validator *p, void* obj){

    PreviousValueValidator *validator = (PreviousValueValidator *)p;
    ir_detect_info_t *info = (ir_detect_info_t*)obj;
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
}
#endif