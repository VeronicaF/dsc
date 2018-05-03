//
// Created by 冯涛 on 2018/4/24.
//

#include <stdlib.h>
#include <iostream>
#include "DLinkList.h"

// 创建一个循环双链表
DLinkList* CreateDList() {
    DLinkList* L = (DLinkList*)malloc(sizeof(DLinkList));
    DNode *p = L;
    L->freq = 0;
    L->prior = L->next = L;
    int input;
    std::cout<< "just input some num🙃" << std::endl << ">>>";
    scanf("%d", &input);

    while (input != 9999) {
        DNode *dNode = (DNode*)malloc(sizeof(DNode));
        dNode->freq = 0;
        dNode->data = input;
        dNode->prior = p;
        dNode->next = L;
        p->next = dNode;
        p = dNode;
        std::cout << ">>>";
        scanf("%d", &input);
    }
    L->prior = p;
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

// 2.17 判断一个双链表是否对称
// 思路：头尾两个指针，向中间扫描，直到值不等或结束
bool symmetry(DLinkList *L) {
    DNode *p = L->next, *q = L->prior;
    while (p != q && p->prior != q) {
        if (p->data != q->data) {
            return false;
        }
        p = p->next;
        q = q->prior;
    }
    return true;
}

// 2.20 题太长不写了
// locate(x)的功能：
// 1. 查找值为x的元素
// 2. 元素的访问频次加一，暂记为f
// 3. 按访问频次重排元素，最近访问的在前面
// 4. 返回一个指向该节点的指针
// 思路：功能一、二、四很好实现，遍历比较即可，
// 功能三，初始状态所有节点的访问频次都为0
// 而多次随机访问后链表中的元素是按访问频次排序的
// 因此从头结点开始遍历，找到访问频次不小于f的第一个节点
// 在此处插入即可
DNode* locate(DLinkList &L, int x) {
    DNode *p = L.next, *q = p;
    while (p != NULL) {
        if (p->data == x) {
            p->freq++;
            // 重排元素
            while (q->freq > p->freq) {
                q = q->next;
            }
            // 如果两个指针指向相同就不用动了
            if (q != p) {
                // 从当前位置删除
                p->prior->next = p->next;
                if (p->next) {
                    p->next->prior = p->prior;
                }
                // 插入指定位置
                p->next = q;
                p->prior = q->prior;
                q->prior->next = p;
                q->prior = p;
            }
            return q;
        }
        p = p->next;
    }
    return NULL;
}
