//
// Created by 冯涛 on 2018/4/18.
//

#include "../../base.h"

#ifndef DS_SQLIST_H
#define DS_SQLIST_H

#define MAXSIZE 50
#define INITSIZE 100

typedef struct {
    ELEM_TYPE data[MAXSIZE];
    int length;
} staticSqList;

typedef struct {
    ELEM_TYPE *data;
    int maxSize, length;
} dynamicSqList;

int InitList(dynamicSqList *L);
bool ListInsert(dynamicSqList* L, int i, ELEM_TYPE elem);
bool ListDelete(dynamicSqList* L, int i, ELEM_TYPE* elem);
void PrintList(dynamicSqList L);
int LocateElem(dynamicSqList L, ELEM_TYPE elem);

// exercises
ELEM_TYPE DelMin(dynamicSqList* L);
void ReverseList(dynamicSqList* L);
void DelX1(dynamicSqList *L, ELEM_TYPE x);
void DelX2(dynamicSqList *L, ELEM_TYPE x);
void DelST(dynamicSqList* L, ELEM_TYPE s, ELEM_TYPE t);
void DelSame(dynamicSqList* L);
dynamicSqList Merge(dynamicSqList L1, dynamicSqList L2);
void SearchExchangeInsert(dynamicSqList* L, ELEM_TYPE x);
void converse1(int *arr, int p, int n);
void reverse(int arr[], int low, int high);
void converse2(int* arr, int p, int n);
int MidSearch1(int *A, int *B, int L);

#endif //DS_SQLIST_H
