#include <iostream>
#include "base.h"
#include "linearList/linkList/linkList.h"

int main() {
    LNode *N1 = INIT_L_NODE, *N2 = INIT_L_NODE, *N3 = INIT_L_NODE;
    N1->data = 1, N2->data = 2, N3->data = 3;
    N1->next = N2;
    N2->next = N3;
    N3->next = NULL;
    LinkList *L1 = INIT_LINK_LIST;
    L1->next = N3;
    LinkList *L2 = INIT_LINK_LIST;
    L2->next = N1;
    std::cout << findCommon(L1, L2)->data << std::endl;
}