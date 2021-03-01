//
// Created by redmk on 2021-03-01.
//
#include "limits.h"
#include "db_read.h"

#define newDatabase(fileName) {{fileName, _average_processor}, 0}

static int _get_diff_max_min(FILE * fp);
static void _average_processor(file_context_t* this, FILE * fp);

int get_average(const char* fileName){
    db_context_t db = newDatabase(fileName);
    read_txt_file(&db.base);
    return db.average;
}

static int _get_diff_max_min(FILE * fp){
    int min = INT_MAX;
    int max = INT_MIN;
    char buf[256];

    while ((fgets(buf, sizeof(buf), fp)) != NULL) {
        if (buf[0] == '\n') return -1; // 空行を発見したら-1を返す。
        int value = atoi(buf);
        min = min > value ? value : min;
        max = max < value ? value : max;
    }

    return max - min;
}


static void _average_processor(file_context_t* this, FILE * fp){
    db_context_t* p = (db_context_t*)this;
    p->average = _get_diff_max_min(fp);
}