#include <iostream>
#include "LL.h"
#include "ordered.h"
#include "unordered.h"



int main() {
    orderedLinkedList<int> list;

    int temp;
    cin >> temp;

    while(temp != -99)
    {
        list.insert(temp);
        cin >> temp;
    }

    cout << list;
    int a = 13;
    list.deleteNode(a);
    cout << list;
}
