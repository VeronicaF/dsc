//
// Created by 冯涛 on 2018/4/20.
//

#include "../../base.h"

#ifndef DS_LINKLIST_H
#define DS_LINKLIST_H

#define INIT_LINK_LIST (LinkList*)malloc(sizeof(LinkList))
#define INIT_L_NODE (LNode*)malloc(sizeof(LNode))

typedef struct LNode {
    ELEM_TYPE data;
    struct LNode* next;
} LNode, LinkList;

LinkList* createList1();
LinkList* createList2();
LNode* getElem(LinkList* L, int i);
LNode* locateElem(LinkList* L, int elem);
void insertWithIndex(LinkList *L, int i, int elem);
void insertBeforeElem(LNode* N, int elem);
void deleteWithIndex(LinkList* L, int i);
int getLength(LinkList* L);
void printReverse(LinkList *L);
void printList(LinkList *L);
void deleteMin(LinkList *L);
void reverseList(LinkList *L);
void sort(LinkList *L);
void deleteRange(LinkList *L, int low, int high);
int len(LinkList *L);
LNode* findCommon(LinkList *L1, LinkList *L2);

#endif //DS_LINKLIST_H