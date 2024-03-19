#include <iostream>
#include "test.h"
using namespace std;

int main()
{
    linkedListType<int> lists;
    nodeType<int> *node,*node1;
    lists.insertFirst(98);
    lists.insertFirst(75);
    lists.insertFirst(65);
    lists.insertLast(72);
    cout << "Empty: " << lists.isEmptyList() << endl;
    cout << "length: " << lists.length() << endl;
    cout << "Back: " << lists.back() << " Front: " << lists.front() << endl;
    lists.print();
    cout << endl;
    node = lists.search(65);
    cout << node->info << endl;
    lists.deleteNode(4);
    lists.deleteNode(75);
    lists.print(); cout << endl;
    lists.deleteNode(65);
    lists.deleteNode(98);
    lists.deleteNode(72);
    lists.deleteNode(1);

    cout << lists;
    lists.destroyList();
    cout << "\n Empty: " << lists.isEmptyList() << endl;
    cout << "length: " << lists.length() << endl;}