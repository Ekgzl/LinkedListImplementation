//
// Created by enes4 on 3/25/2024.
//

#ifndef LINKEDLIST_LL_H
#define LINKEDLIST_LL_H

#include <iostream>
using namespace std;

template <class T>
struct node {
    T info;
    node<T> *link;
};

template <class T>
class LL {
protected:
    node<T> *head, *last;
    int count;
public:
    LL();
    ~LL();
    bool isEmptyList();
    int length();
    T back();
    T front();
    void destroyList();
    node<T>* search(T&);
    void insertFirst(T&);
    void insertLast(T&);
    void deleteNode(T&);

    friend ostream& operator<<(ostream& os, const LL<T>& list) {
        node<T>* current = list.head;
        while (current != nullptr) {
            os << current->info;
            if (current->link != nullptr)
                os << " -> ";
            current = current->link;
        }
        return os;}
};


    template <class T>
    LL<T>::LL()
    {
        count = 0;
        head = NULL;
        last = NULL;
    }

    template <class T>
    LL<T>::~LL()
    {
        destroyList();
    }

    template <class T>
    bool LL<T>::isEmptyList()
    {
        return (count == 0);
    }

    template <class T>
    int LL<T>::length()
    {
        return count;
    }

    template <class T>
    T LL<T>::front()
    {
        return head->info;
    }

    template <class T>
    T LL<T>::back()
    {
        return last->info;
    }

    template <class T>
    void LL<T>::destroyList()
    {
        node<T>* current;

        while(head != NULL)
        {
            current = head;
            head = head->link;
            delete current;
        }
        count = 0;
        last = NULL;
    }






#endif //LINKEDLIST_LL_H
