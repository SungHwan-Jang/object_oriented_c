//
// Created by admin on 2021-02-16.
//

// ear state 비교하고 알람, previous는 abs 더 큰값을 저장.

#ifndef CHAINOFRESPONSIBILITY01_LET_VALIDATOR_H
#define CHAINOFRESPONSIBILITY01_LET_VALIDATOR_H
#include "stdbool.h"

#define IR_DETECT_MIN_THRESHOLD     60
#define IR_DETECT_MAX_THRESHOLD     150
#define IR_DETECT_DIFF_THRESHOLD    80

typedef struct _validator{
    bool (* const check)(struct Validator *pThis, void* info);
}Validator;

typedef struct{
    Validator this;
    const int diff;
}PreviousValueValidator;

typedef struct{
    Validator this;
    const unsigned int min;
    const unsigned int max;
}RangeValidator;

typedef enum {
    IN_EAR_ON_INFO,
    IN_EAR_OFF_INFO,
    IN_EAR_NONE_INFO,
}ir_in_ear_info;

typedef struct _ir_detect_in_ear_info{
    unsigned int previousDistance;
    unsigned int currentDistance;
    bool isAlarm;
    ir_in_ear_info earState;
    Validator * const pRangeValidate;
    Validator * const pDiffValidate;
}ir_detect_info_t;

void initialize_ir_info_instance(void);
ir_in_ear_info get_ir_ear_state(unsigned int curDistance);

bool validateRange(Validator *p, void* info);
bool validateDiff(Validator *p, void* info);

#define newIrDetectInfo(rangeCheck, diffCheck) \
    {0, 0, false, IN_EAR_NONE_INFO, rangeCheck, diffCheck}

#define newRangeValidator() \
    {validateRange, (IR_DETECT_MIN_THRESHOLD), (IR_DETECT_MAX_THRESHOLD)}

#define newDiffValidator() \
    {validateDiff, (IR_DETECT_DIFF_THRESHOLD)}

#endif //CHAINOFRESPONSIBILITY01_LET_VALIDATOR_H
