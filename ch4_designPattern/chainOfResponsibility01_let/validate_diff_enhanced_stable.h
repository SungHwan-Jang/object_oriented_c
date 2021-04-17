//
// Created by admin on 2021-02-22.
//

#ifndef CHAINOFRESPONSIBILITY01_LET_VALIDATE_DIFF_ENHANCED_STABLE_H
#define CHAINOFRESPONSIBILITY01_LET_VALIDATE_DIFF_ENHANCED_STABLE_H

#include "stdbool.h"

#define RING_BUFFER_MAX                     8 // 32 byte mem
#define TIMER_PERIOD                        500

#define IR_DETECT_MIN_THRESHOLD             20
#define IR_DETECT_MAX_THRESHOLD             200

#define IR_DETECT_DIFF_STABLE_THRESHOLD      20
#define IR_DETECT_DIFF_UPPER_THRESHOLD      70

typedef struct _validator{
    bool (* const check)(struct Validator *pThis, void* info);
}Validator; // inheritance form.

typedef struct _custom_ring_buffer{
    unsigned int buf[RING_BUFFER_MAX];
    unsigned int idx;
    const unsigned int last; // buf last
    bool maxFlag; // for detecting max filled
    void (* const push)(struct _custom_ring_buffer *pThis, const unsigned int curDistance);
    unsigned int (* const pop)(struct _custom_ring_buffer *pThis);
    void (* const reset)(struct _custom_ring_buffer *pThis);
}custom_ring_buffer_t;

typedef struct{
    Validator this;
    const unsigned int stableThr;
    int upperThr; // need calib
}DiffentialValidator;

typedef struct{
    Validator this; // it must be located first. because of inheritance.
    const unsigned int min; // need calib
    const unsigned int max; // need calib
}RangeValidator;

typedef enum {
    IN_EAR_ON_INFO,
    IN_EAR_OFF_INFO,
    IN_EAR_NONE_INFO,
}ir_in_ear_info;

typedef struct _ir_detect_in_ear_info{
    custom_ring_buffer_t* bufInstance;
    unsigned int previousDistance;
    unsigned int currentDistance;
    bool isAlarm;
    ir_in_ear_info earState;
    Validator * const pRangeValidate;
    Validator * const pDiffValidate;
}ir_detect_info_t;


void initialize_ir_info_instance(void);
ir_in_ear_info get_ir_ear_state(unsigned int curDistance);

void insert_ring_buffer (struct _custom_ring_buffer *pThis, const unsigned int curDistance);
unsigned int get_average_ring_buffer (struct _custom_ring_buffer *pThis);
void reset_buffer (struct _custom_ring_buffer *pThis);
bool validateRange(Validator *p, void* info);
bool validateDiff(Validator *p, void* info);

#define newCustomBuffer() \
    {{0,}, 0, (RING_BUFFER_MAX - 1), false, insert_ring_buffer, get_average_ring_buffer, reset_buffer}

#define newIrDetectInfo(buf, rangeCheck, diffCheck) \
    {buf, 0, 0, false, IN_EAR_NONE_INFO, rangeCheck, diffCheck}

#define newRangeValidator() \
    {validateRange, (IR_DETECT_MIN_THRESHOLD), (IR_DETECT_MAX_THRESHOLD)}

#define newDiffValidator() \
    {validateDiff, (IR_DETECT_DIFF_STABLE_THRESHOLD), (IR_DETECT_DIFF_UPPER_THRESHOLD)}

#endif //CHAINOFRESPONSIBILITY01_LET_VALIDATE_DIFF_ENHANCED_STABLE_H
