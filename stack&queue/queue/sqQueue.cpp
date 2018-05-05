//
// Created by 冯涛 on 05/05/2018.
//

#include "sqQueue.h"

void initQueue(sqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool isEmpty(sqQueue Q) {
    return Q.rear == Q.front;
}

// 从队尾插入队列
bool enQueue(sqQueue &Q, ELEM_TYPE x) {
    // 首先判断队列是否满了
    if ((Q.rear + 1) % MAX_SIZE == Q.front) {
        return false;
    }
    // 插入元素，队尾指针后移
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1 ) % MAX_SIZE;
    return true;
}

bool deQueue(sqQueue &Q, ELEM_TYPE &x) {
    if (isEmpty(Q)) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    return true;
}


