#include <iostream>
#include "base.h"
#include "linearList/linkList/linkList.h"
#include "linearList/linkList/DLinkList.h"

int main() {
    LinkList *L = createList2();
    Deduplicate2(*L, 10);
    printList(L);
}