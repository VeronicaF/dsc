//
// Created by 冯涛 on 2018/4/20.
// 单链表
//

#include "linkList.h"
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

// 2.9 升序输出节点数据并释放内存
// 思路：遍历链表，找到最大节点与之前一个节点，输出数据，释放节点。
// time: Ø(n^2)
// space: Ø(1)
void printAndFree(LinkList &L) {
    LNode *head = L.next, *prev = head, *min = head, *minPrev = &L;

    while (L.next != nullptr) {
        while (head != nullptr) {
            if (head->data < min->data) {
                min = head;
                minPrev = prev;
            }
            prev = head;
            head = head->next;
        }
        std::cout << min->data << "->";
        minPrev->next = min->next;
        free(min);
        head = L.next;
        minPrev = &L;
        min = head;
    }

}

// 2.10 按奇偶分解链表
// 思路：新建头结点L1，L2，遍历L，尾插
// time: Ø(n)
LinkList* breakIn2(LinkList &L) {
    LinkList *L1 = INIT_LINK_LIST, *L2 = INIT_LINK_LIST;
    LNode *p = L.next, *next, *s1 = L1, *s2 = L2;
    int index = 0;
    while (p != nullptr) {
        next = p->next;
        if (index % 2 == 0) {
            s1->next = p;
            s1 = p;
        } else {
            s2->next = p;
            s2 = p;
        }
        index++;
        p = next;
    }
    s1->next = nullptr;
    s2->next = nullptr;
    L = *L1;
    return L2;
}

// 2.11 按奇偶拆分链表，偶数链表反序
// 思路：新建头结点L1，L2，遍历，头插
// time: Ø(n)
LinkList* breakIn2Reverse(LinkList &L) {
    LinkList *L1 = INIT_LINK_LIST, *L2 = INIT_LINK_LIST;
    L2->next = nullptr;
    LNode *p = L.next, *s = L1, *next;
    int index = 0;
    while (p != nullptr) {
        next = p->next;
        if (index % 2 == 0) {
            s->next = p;
            s = p;
        } else {
            p->next = L2->next;
            L2->next = p;
        }
        p = next;
        index++;
    }
    s->next = nullptr;
    L = *L1;
    return L2;
}

// 2.12 升序单链表去重
// 思路：遍历链表，维护当前节点与前一个节点，如相同删除当前节点
// time: Ø(n)
void Deduplicate(LinkList &L) {
    LNode *prev, *p, *next;
    if (L.next == nullptr || L.next->next == nullptr) {
        return;
    }
    prev = L.next, p = prev->next;
    while (p != nullptr) {
        next = p->next;
        if (p->data == prev->data) {
            prev->next = p->next;
            free(p);
        } else {
            prev = p;
        }
        p = next;
    }
}

// 2.13 合并两个递增的单列表为一个递减的单列表
// 思路：维护两个指针p1,p2，新建一个链表，依次取两个指针中的较小值，头插入新的链表
// time: Ø(m + n)
LinkList* mergeList(LinkList &L1, LinkList &L2) {
    LinkList *L = INIT_LINK_LIST;
    L->next = nullptr;
    LNode *s1 = L1.next, *s2 = L2.next, *next;
    while (s1 && s2) {
        if (s1->data <= s2->data) {
            next = s1->next;
            s1->next = L->next;
            L->next = s1;
            s1 = next;
        } else {
            next = s2->next;
            s2->next = L->next;
            L->next = s2;
            s2 = next;
        }
    }
    while (s2) {
        next = s2->next;
        s2->next = L->next;
        L->next = s2;
        s2 = next;
    }
    while (s1) {
        next = s1->next;
        s1->next = L->next;
        L->next = s1;
        s1 = next;
    }
    return L;
}

// 2.14 从两个递增的链表中找出公共元素，合成新链表
// 思路：维护两个指针分别指向两个链表，每次比较指向的元素的值
// 将较小的那个指针后移，直到一个指针为空
// 遇到相等的元素则新建节点，采用尾插
LinkList* Union(LinkList *L1, LinkList *L2) {
    LinkList *L = INIT_LINK_LIST;
    LNode *p1 = L1->next, *p2 = L2->next, *p = L, *n;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->data == p2->data) {
            n = INIT_L_NODE;
            n->data = p1->data;
            p->next = n;
            p = n;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->data < p2->data) {
            p1 = p1->next;
        } else {
            p2 = p2->next;
        }
    }
    p->next = nullptr;
    return L;
}

// 2.15 L1, L2 表示两个元素递增排列的集合，求交集，并存放于L1，释放其他节点
// 思路：遍历两个链表，操作基本相同，多了释放节点
LinkList intersection(LinkList &L1, LinkList *L2) {
    LNode *p1 = L1.next, *p2 = L2->next, *p = &L1, *temp;
    while (p1 && p2) {
        if (p1->data == p2->data) {
            p->next = p1;
            p = p1;
            temp = p2;
            p1 = p1->next;
            p2 = p2->next;
            free(temp);
        } else if (p1->data < p2->data) {
            temp = p1;
            p1 = p1->next;
            free(temp);
        } else {
            temp = p2;
            p2 = p2->next;
            free(temp);
        }
    }
    while (p1) {
        temp = p1;
        p1 = p1->next;
        free(temp);
    }
    while (p2) {
        temp = p2;
        p2 = p2->next;
        free(temp);
    }
    p->next = NULL;
    return L1;
}

// 2.16 L1， L2 代表两个序列，判断L2是否为L1的连续子序列
// 思路：两个指针分别指向L1, L2，取L2的第一个元素的值记为head
// 遍历L1,每当L1中元素与head相等，同时遍历两个序列
// 如果L1剩余长度不小于L2，且对应的元素值都相等返回true，否则false
bool pattern(LinkList *L1, LinkList *L2) {
    LNode *p = L1->next, *p1 = p, *p2 = L2->next;
    // p1 p2 都不是空指针
    while(p1 && p2) {
        // 如果两个节点值相等，两个指针同时后移
        if (p1->data == p2->data) {
            p1 = p1->next;
            p2 = p2->next;
        } else {
            // 否则将指针复位
            p = p->next;
            p1 = p;
            p2 = L2->next;
        }
    }
    return p2 == nullptr;
}

// 2.18 合并两个循环单链表为一个循环单链表
// 思路：遍历链表L1至尾部，接上L2，处理头尾节点
// 现有链表带头结点，处理起来很麻烦，不写了
LinkList* link(LinkList &L1, LinkList &L2) {

}

// 2.19 找到值最小的节点并删除
// 思路：遍历链表每次找到值最小的节点并记录它的前一个节点，删除之
// 最后删除头结点
// time: Ø(n^2)
// EZPZ，不写了
void delAll(LinkList &L) {

}

// 2.21 查找倒数第K个元素
// 思路1：先求出数组的长度，然后根据长度与K的关系决定从头开始查找还是从尾部开始查找
// 好吧。。。五分没了
// 思路二：两个指针p, q；p先后移K位，然后p,q一起后移直到p到底，扫描一次即可
// 代码很简单不写了，主要是思路

// 2.22
// 此题与2.8思路相通，先从尾部对齐两个链表然后一起遍历即可

// 2.23
// 思路一：与去重类似，依次遍历，时间复杂度Ø(n^2),空间复杂度Ø(1)
// 题目要求时间复杂度尽量高，因此尽量使用空间换时间
// 使用查表法记录元素是否出现（表可以是hash map，数组也行）
void Deduplicate2(LinkList &L, int n) {
    int arr[n + 1], data;
    for (int i = 0; i < n + 1; i++) {
        arr[i] = 0;
    }
    LNode *p = L.next, *prev = &L;
    while (p) {
        data = p->data < 0 ? -p->data : p->data;
        if (arr[data] != 0) {
            prev->next = p->next;
            free(p);
            p = prev->next;
        } else {
            arr[data]++;
            prev = p;
            p = p->next;
        }
    }
}


