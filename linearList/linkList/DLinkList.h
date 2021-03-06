//
// Created by 冯涛 on 2018/4/24.
//

#include "../../base.h"

#ifndef DS_DLIST_H
#define DS_DLIST_H

#define INIT_D_LINK_LIST (DLinkList*)malloc(sizeof(DLinkList));
#define INIT_D_NODE (DNode*)malloc(sizeof(DNode));

typedef struct DNode {
    ELEM_TYPE data;
    // 只有2.20用到
    int freq;
    struct DNode* next;
    struct DNode* prior;
} DNode, DLinkList;

DLinkList* CreateDList();
void insertAfter(DNode* N, ELEM_TYPE data);
void insertBefore(DNode* N, ELEM_TYPE data);
void deleteNode(DNode* N);
bool symmetry(DLinkList *L);
DNode* locate(DLinkList &L, int x);

#endif //DS_DLIST_H
