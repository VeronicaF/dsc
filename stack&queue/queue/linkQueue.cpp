//
// Created by 冯涛 on 05/05/2018.
//

#include <cstdlib>
#include "linkQueue.h"

void initQueue(linkQueue &Q) {
    Q.front = Q.rear = (linkNode*)malloc(sizeof(linkNode));
    Q.front->next = NULL;
}

bool isEmpty(linkQueue Q) {
    return Q.front == Q.rear;
}

void enQueue(linkQueue &Q, ELEM_TYPE x) {
    linkNode *s = (linkNode*)malloc(sizeof(linkNode));
    s->data = x;
    s->next = Q.rear->next;
    Q.rear->next = s;
    Q.rear = s;
}

bool deQueue(linkQueue &Q, ELEM_TYPE &x) {
    linkNode *p;
    if (isEmpty(Q)) {
        return false;
    }
    p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    // 如果删除的这个节点是尾指针指向的节点
    // 说明只有一个节点，删除后变为空队列
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}
