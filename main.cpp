#include <iostream>
#include "base.h"
#include "linearList/linkList/linkList.h"

int main() {
    LinkList *L1 = createList2();
    Deduplicate(*L1);
    printList(L1);
}