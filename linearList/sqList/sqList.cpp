//
// Created by 冯涛 on 2018/4/18.
//

#include <stdlib.h>
#include <stdio.h>
#include "sqList.h"
#include "../../base.h"

status InitList(dynamicSqList* L) {
    L->data = (ELEM_TYPE*) malloc(sizeof(ELEM_TYPE) * INITSIZE);
    if (!L->data) {
        exit(OVERFLOW);
    }
    L->length = 0;
    L->maxSize = INITSIZE;
    return 0;
}

int Length(dynamicSqList L) {
    return L.length;
}

bool ListInsert(dynamicSqList* L, int i, ELEM_TYPE elem) {
    if (i < 1 || i > L->length + 1) {
        return FALSE;
    }
    if (L->length >= L->maxSize) {
        return FALSE;
    }

    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = elem;
    L->length += 1;
    return TRUE;
}

bool ListDelete(dynamicSqList* L, int i, ELEM_TYPE* elem) {
    if (i < 1 || i > L->length) {
        return FALSE;
    }

    *elem = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return TRUE;
}

int LocateElem(dynamicSqList L, ELEM_TYPE elem) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == elem) {
            return i + 1;
        }
    }
    return 0;
}

void PrintList(dynamicSqList L) {
    if (L.length == 0) {
        printf("empty list");
    }
    printf("[");
    for (int i = 0; i < L.length; i++) {
        printf("%d: %d, ", i, L.data[i]);
    }
    printf("]\n");
}

// 2.1 删除最小值并用最后一个元素填充
ELEM_TYPE DelMin(dynamicSqList* L) {
    int index = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] < L->data[index]) {
            index = i;
        }
    }
    L->data[index] = L->data[L->length - 1];

    return L->data[index];
}

// 2.2 翻转顺序表，空间复杂度为Ø(1)
void ReverseList(dynamicSqList* L) {
    ELEM_TYPE temp;
    for (int i = 0; i < L->length / 2; i++) {
        temp = L->data[i];
        L->data[i] = L->data[L->length - i - 1];
        L->data[L->length - i - 1] = temp;
    }
}

// 2.3 删除值为x的元素 v1
void DelX1(dynamicSqList *L, ELEM_TYPE x) {
    if (L->length == 0) {
        exit(1);
    }
    int i = 0, j = 0;
    for (; i < L->length; i++) {
        if (L->data[i] != x) {
            L->data[j] = L->data[i];
            j++;
        }
    }
    L->length = j;
}

// 2.3 v2
void DelX2(dynamicSqList* L, ELEM_TYPE x) {
    if (L->length == 0) {
        exit(1);
    }
    int i = 0, j = 0;
    for (; i < L->length; i++) {
        if (L->data[i] == x) {
            j++;
        }
        L->data[i] = L->data[i + j];
    }
    L->length -= j;
}

// 2.4 删除范围内元素
void DelST(dynamicSqList* L, ELEM_TYPE s, ELEM_TYPE t) {
    if (L->length == 0 || s >= t) {
        exit(1);
    }
    int i = 0, j = 0;
    for (; i < L->length; i++) {
        if (L->data[i] > s && L->data[i] < t) {
            continue;
        }
        L->data[j] = L->data[i];
        j++;
    }
    L->length = j;
}

// 2.6 有序顺序表去重
void DelSame(dynamicSqList* L) {
    if (L->length == 0) {
        exit(1);
    }
    int i = 1;
    for (int j = 1; j < L->length; j++) {
        if (L->data[i - 1] != L->data[j]) {
            L->data[i] = L->data[j];
            i++;
        }
    }
    L->length = i;
}

// 2.7 有序顺序表合并

dynamicSqList Merge(dynamicSqList L1, dynamicSqList L2) {
    dynamicSqList L3;
    InitList(&L3);
    if (L1.length + L2.length > L3.maxSize) {
        exit(-1);
    }
    int i = 0, j = 0;

    while (i < L1.length && j < L2.length) {
        if (L1.data[i] <= L2.data[j]) {
            L3.data[i + j] = L1.data[i];
            i++;
        } else {
            L3.data[i + j] = L2.data[j];
            j++;
        }
    }

    while (i < L1.length) {
        L3.data[i + j] = L1.data[i];
        i++;
    }
    while (j < L1.length) {
        L3.data[i + j] = L2.data[j];
        j++;
    }
    L3.length = L1.length + L2.length;
    return L3;
}

// 2.8
void Reverse(ELEM_TYPE arr[]) {

}

// 2.9 二分查找
void SearchExchangeInsert(dynamicSqList* L, ELEM_TYPE x) {
    int low = 0, high = L->length, mid = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (L->data[mid] == x) {
            break;
        }
        L->data[mid] > x ? (high = mid - 1) : (low = mid + 1);
    }

    if (L->data[mid] == x && L->data[L->length - 1] != x) {
        L->data[mid] = L->data[mid + 1];
        L->data[mid] = x;
    }

    if (low > high) {
        for (int i = L->length; i >= low; i--) {
            L->data[i] = L->data[i - 1];
        }
        L->data[low] = x;
        L->length++;
    }
}

// 2.10
// 思想：可以看成三次翻转数组
void reverse(int arr[], int low, int high) {
    // 注意：循环执行的次数的计算
    for (int i = 0; i < (high - low + 1)/2; i++) {
        int temp = arr[low + i];
        arr[low + i] = arr[high - i];
        arr[high - i] = temp;
    }
}

void converse1(int *arr, int p, int n) {
    reverse(arr, 0, p - 1);
    reverse(arr, p, n - 1);
    reverse(arr, 0, n - 1);
}

// 用辅助数组存储要放到后面的值，将n-p个值前移
void converse2(int* arr, int p, int n) {
    int temp[p];

    for (int i = 0; i < p; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < n - p; i++) {
        arr[i] = arr[i + p];
    }
    for (int i = 0; i < p; i++) {
        arr[n - p + i] = temp[i];
    }

}

// 2.11
// 非最优解
// 思想：两个升序序列，用mid存储中位数的值，遍历A、B，每次取较小值，并分别用i、j记录位置
// 当i + j == (A + B) / 2 时结束
// 时间复杂度：Ø(n)
int MidSearch1(int *A, int *B, int L) {
    int i = 0, j = 0, mid;
    while (i + j < L) {
        if (A[i] <= B[j]) {
            mid = A[i];
            i++;
        } else {
            mid = B[i];
            j++;
        }
    }
    return mid;
}

// 2.11
// 分治
// TODO: 完成算法
int midSearch2(int* A, int* B, int L) {
    int s1 = 0, d1 = L - 1, mid1, s2 = 0, d2 = L - 1, mid2;
    while (s1 != d1 || s2 != d2) {
        mid1 = s1 + d1 / 2;
        mid2 = s2 + d2 / 2;

        if (A[mid1] == B[mid2]) {
            return A[mid1];
        }
        if (A[mid1] < B[mid2]) {
            if ((d1 + s1) % 2 == 0) {
                s1 = mid1;
                d2 = mid2;
            } else {

            }
        }

    }
}

// 2.12
// 思想：从前向后扫描，用prime记录可能的主元素，用count记录出现次数
// 扫描过程中如果遇到相同元素count+1，否则-1，
// 当count == 0，更新prime为下个元素。
// 可得到出现次数最多的元素
// 扫描结束后再次顺序扫描，检查prime出现的次数是否大于n / 2
int Majority(int* A, int n) {
    int prime, count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            prime = A[i];
        }
        if (prime == A[i]) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;

    for (int i = 0; i < n; i++) {
        A[i] == prime && count++;
    }

    return count > n/2 ? prime : -1;

}