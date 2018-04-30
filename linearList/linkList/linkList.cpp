//
// Created by 冯涛 on 2018/4/20.
// 单链表
//

#include "linkList.h"
#include "../../base.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// 创建：头插法
LinkList* createList1() {
    // 初始化头结点
    LinkList* L = INIT_LINK_LIST;
    LNode* s; int x;
    L->next = NULL;

    printf("just input some num🙃\n>>>");
    scanf("%d", &x);
    while(x != 9999) {
        // 初始化一个新的节点
        s = INIT_L_NODE;
        // 写入数据
        s->data = x;
        // 新节点的next指向原头结点的next
        s->next = L->next;
        // 头结点的next指向新节点
        L->next = s;
        printf(">>>");
        scanf("%d", &x);
    }
    return L;
}

// 创建：尾插法
LinkList* createList2() {
    int x;
    LNode* s;
    // 初始化头结点
    LinkList* L = INIT_LINK_LIST;
    // 尾节点指针初始化
    LNode* r = L;

    printf("just input some num🙃\n");
    printf(">>>");
    scanf("%d", &x);
    while (x != 9999) {
        // 初始化新节点
        s = INIT_L_NODE;
        s->data = x;
        // 原尾节点的next指向新节点
        r->next = s;
        // 尾节点指针指向新节点
        r = s;
        printf(">>>");
        scanf("%d", &x);
    }
    // 尾节点的next置NULL
    r->next = NULL;
    return L;
}

// 按序号查找，注意：元素序号从`1`开始，0号为头结点
LNode* getElem(LinkList* L, int i) {
    LNode* temp = L;

    if (i < 0) {
        return NULL;
    }

    for (int j = 1; j <= i; j++) {
        temp = temp->next;
        if (temp == NULL) {
            return NULL;
        }
    }

    return temp;
}

// 按值查找
LNode* locateElem(LinkList* L, int elem) {
    LNode* temp = L->next;

    while (temp != NULL) {
        if (temp->data != elem) {
            temp = temp->next;
        } else {
            return temp;
        }
    }

    return temp;
}

// 指定位置插入
void insertWithIndex(LinkList *L, int i, int elem) {
    // 找到目标位置的前一个节点temp
    LNode* temp = getElem(L, i - 1);
    LNode* s = INIT_L_NODE;
    s->data = elem;
    // 在temp节点后插
    s->next = temp->next;
    temp->next = s;
    // 找到目标节点的方法
//    LNode* temp = getElem(L, i);
//    insertBeforeElem(temp);
}

// 指定节点前插入
void insertBeforeElem(LNode* N, int elem) {
    LNode* s = INIT_L_NODE;
    // 将新节点插入到指定节点之后
    s->next = N->next;
    N->next = s;
    // 交换数据域
    s->data = N->data;
    N->data = elem;
}

// 删除指定位置元素
// TODO: 检查删除位置的合法性
void deleteWithIndex(LinkList* L, int i) {
    // 从指定位置的前一个节点来操作
    LNode* temp = getElem(L, i - 1);
    temp->next = temp->next->next;
    free(temp->next);
}

// 删除指定元素
void deleteWithElem(LNode* N) {
    LNode* temp = N->next;
    // 删除该元素后继元素，并将该元素复制为其后继元素
    N->data = temp->data;
    N->next = temp->next;
    free(temp);
}

// 求表长，带头结点
int getLength(LinkList* L) {
    return L->next == NULL ? 0 : 1 + getLength(L->next);
}

// 打印一个链表
void printList(LinkList *L) {
    if (L != nullptr) {
        std::cout << L->data << "->";
        printList(L->next);
    }
}

// 求表长, 带表头
int len(LinkList *L) {
    return (L != NULL ? 1 + len(L->next) : -1);
}

// 2.3 反向输出节点中的值，带头结点
void printReverse(LinkList *L) {
    if (L->next == nullptr) {
        return;
    }
    printReverse(L->next);
    std::cout << L->data << std::endl;
}

// 2.4 删除最小值的节点
void deleteMin(LinkList *L) {
    LNode *preMin = L, *min = L->next, *pre = L, *p = L->next;
    while (p != nullptr) {
        if (p->data < min->data) {
            preMin = pre;
            min = p;
        }
        pre = p;
        p = p->next;
    }
    preMin->next = min->next;
}

// 2.5 就地翻转链表
void reverseList(LinkList *L) {
    LNode *p = L->next, *next;
    // 摘下头结点
    L->next = NULL;
    while (p != NULL) {
        next = p->next;
        p->next = L->next;
        L->next = p;
        p = next;
    }
}

// 2.6 链表排序
void sort(LinkList *L) {
    LNode *next;
    // 新建有序链表
    LinkList *r = INIT_LINK_LIST;
    r->next = L->next;
    // p指向L中当前节点
    LNode *p = L->next->next;
    r->next->next = NULL;

    // prev存放插入位置的前一个节点
    LNode *prev = r;

    while (p != NULL) {
        // 保存下一个节点
        next = p->next;
        while (prev->next != NULL && p->data > prev->next->data) {
            prev = prev->next;
        }

        // 在节点后插入
        p->next = prev->next;
        prev->next = p;
        p = next;
        prev = r;
    }

    *L = *r;
}

// 2.7 删除范围内元素
void deleteRange(LinkList *L, int low, int high) {
    LNode *prev = L, *p = L->next;
    while(p != NULL) {
        if (p->data > low && p->data < high) {
            prev->next = p->next;
            free(p);
        } else {
            prev = p;
        }
        p = prev->next;
    }
}

// 2.8 找公共节点，应该认识到从某一节点开始，后续节点都相同
LNode* findCommon(LinkList *L1, LinkList *L2) {
    int len1 = len(L1);
    int len2 = len(L2);
    int dist;
    LinkList *LongList, *ShortList;
    if (len1 > len2) {
        LongList = L1->next;
        ShortList = L2->next;
        dist = len1 - len2;
    } else {
        LongList = L2->next;
        ShortList = L1->next;
        dist = len2 - len1;
    }

    while (dist--) {
        LongList = LongList->next;
    }

    while (LongList != NULL) {
        if (LongList == ShortList) {
            return LongList;
        }
        LongList = LongList->next;
        ShortList = ShortList->next;
    }
    return NULL;
}