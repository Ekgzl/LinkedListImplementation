# C++ LinkedList Implementation

This repository contains implementations of linked list data structure in C++ language. Linked list is a data structure that stores data elements as nodes and establishes connections between these nodes.

## File Structure

- **LL.h**: Contains the general structure and basic functions of the linked list.
- **ordered.h**: Defines the ordered linked list class. Elements are added in a sorted order and this order is maintained.
- **unordered.h**: Defines the unordered linked list class. The order of elements doesn't matter when adding.
- **main.cpp**: Test program demonstrating the usage of linked lists.

## How to Use

1. Clone or download the project to your computer.
2. Compile the `main.cpp` file with your C++ compiler (`g++`, `clang++`, etc.).
3. Run the compiled program to test linked list operations.

## Example Usage

```cpp
#include <iostream>
#include "LL.h"
#include "ordered.h"
#include "unordered.h"

int main() {
    orderedLinkedList<int> list;

    int temp;
    std::cout << "Enter integers (-99 to stop): ";
    std::cin >> temp;
    while(temp != -99) {
        list.insert(temp);
        std::cin >> temp;}

    std::cout << "List: " << list;

    int itemToDelete = 13;
    list.deleteNode(itemToDelete);
    std::cout << "List after deletion: " << list;

    return 0;
}
