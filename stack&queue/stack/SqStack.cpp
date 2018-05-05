//
// Created by 冯涛 on 05/05/2018.
//

#include "SqStack.h"

void initStack(sqStack &S) {
    S.top = -1;
}

bool emptyStack(sqStack S) {
    return S.top == -1;
}

bool push(sqStack &S, ELEM_TYPE x) {
    if (S.top > MAX_SIZE - 1) {
        return false;
    }
    S.top++;
    S.data[S.top] = x;
    return true;
}

bool pop(sqStack &S, ELEM_TYPE &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top];
    S.top--;
    return true;
}

bool getTop(sqStack &S, ELEM_TYPE &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top];
    return true;
}


