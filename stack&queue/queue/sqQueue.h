//
// Created by 冯涛 on 05/05/2018.
//

#include "../../base.h"

#ifndef DSINCPP_SQQUEUE_H
#define DSINCPP_SQQUEUE_H

#define MAX_SIZE 100

typedef struct {
    ELEM_TYPE data[MAX_SIZE];
    int front, rear;
} sqQueue;

#endif //DSINCPP_SQQUEUE_H
