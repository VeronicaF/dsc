//
// Created by 冯涛 on 05/05/2018.
//

#include "../../base.h"

#ifndef DSINCPP_SQSTACK_H
#define DSINCPP_SQSTACK_H

#define MAX_SIZE 50

typedef struct {
    ELEM_TYPE data[MAX_SIZE];
    int top;
} sqStack;


#endif //DSINCPP_SQSTACK_H
