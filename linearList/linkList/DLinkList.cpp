#include <stdlib.h>
#include "DLinkList.h"//
// Created by 冯涛 on 2018/4/24.
//

DLinkList* CreateDList(ELEM_TYPE data) {
    DLinkList* L = (DLinkList*)malloc(sizeof(DLinkList));
    L->prior = L->next = NULL;
    L->data = data;
    return L;
}

// 后插
void insertAfter(DNode* N, ELEM_TYPE data) {
    DNode* s = INIT_D_NODE;
    s->data = data;
    if (N->next == NULL) {
        N->next = s;
        s->prior = N;
        s->next = NULL;
    } else {
        N->next->prior = s;
        s->next = N->next;
        s->prior = N;
        N->next = s;
    }
}

// 前插
void insertBefore(DNode* N, ELEM_TYPE data) {
    DNode* s = INIT_D_NODE;
    s->data = data;
    if (N->prior == NULL) {
        s->next = N;
        N->prior = s;
        s->prior = NULL;
    } else {
        N->prior->next = s;
        s->prior = N->prior;
        s->next = N;
        N->prior = s;
    }
}

// 删除节点
void deleteNode(DNode* N) {
    if (N->prior == NULL && N->next != NULL) {
        N->next->prior = NULL;
        free(N);
    } else if (N->next == NULL && N->prior != NULL) {
        N->prior->next = NULL;
        free(N);
    } else if (N->next == NULL && N->prior == NULL) {
        free(N);
    } else {
        N->prior->next = N->next;
        N->next->prior = N->prior;
        free(N);
    }
}

// 删除指定节点前一个节点
