//
// Created by 冯涛 on 05/05/2018.
//
#include "../../base.h"

#ifndef DSINCPP_LINKQUEUE_H
#define DSINCPP_LINKQUEUE_H

typedef struct linkNode {
    ELEM_TYPE data;
    struct linkNode *next;
} linkNode;

typedef struct {
    linkNode *front, *rear;
} linkQueue;

#endif //DSINCPP_LINKQUEUE_H
