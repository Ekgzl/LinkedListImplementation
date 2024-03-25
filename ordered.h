//
// Created by enes4 on 3/25/2024.
//

#ifndef LINKEDLIST_ORDERED_H
#define LINKEDLIST_ORDERED_H

#include "LL.h"

template <class T>
class orderedLinkedList : public LL<T>
        {
        public:
            void insert(T&);
            node<T>* search(T &);
            void insertFirst(T&);
            void insertLast(T&);

    void deleteNode(T &item);
};



    template <class T>
    void orderedLinkedList<T>::insert(T &item)
    {
        node<T> *newNode,*current,*before;
        newNode = new node<T>;
        newNode->info = item;
        newNode->link = NULL;

        if(this->head == NULL) //case 1 empty list
        {
            this->head = newNode;
            this->last = newNode;
            this->count++;
        }
        else
        {
            current = this->head;
            before = NULL;

            while(current != NULL)
            {
                if(current->info >= item)
                {
                    if(current == this->head) // case 2 başa
                    {
                            newNode->link = this->head;
                            this->head = newNode;
                            this->count++;
                            break;
                    }
                    else // case 3 araya
                    {
                            before->link = newNode;
                            newNode->link = current;
                            this->count++;
                            break;
                    }
                }
                else
                {
                    before = current;
                    current = current->link;
                }
            }
            if(current == NULL) //case 4
            {
                this->last->link = newNode;
                this->last = newNode;
            }
        }
    }

    template <class T>
    node<T>* orderedLinkedList<T>::search(T &item)
    {
        node<T> *current = this->head;

        if(this->head == NULL)
            cout << "cannot search in empty list.\n";
        else
        {
            while(current != NULL)
            {
                if(current->info >=item)
                    break;
                else
                    current = current->link;
            }

            if(current->info == item)
                return current;
            else
            {
                cout << "item couldn't find";
                return NULL;
            }
        }
    }

    template <class T>
    void orderedLinkedList<T>::deleteNode(T &item)
    {
        node<T> *before,*current;
        if(this->head == NULL) //case 1
            cout << "cannot delete from empty list";
        else
        {
            current = this->head;
            before = NULL;

            while(current != NULL)
            {
                if(current->info>= item)
                {
                    if(current->info == item)
                    {
                        if(current == this->head) // case 2 baş
                        {
                            this->head = this->head->link;
                            delete current;
                            this->count--;
                            return;
                        }
                        else
                        {
                            before->link = current->link; // case 3 ortada
                            if(before->link == NULL) // case 4 last
                                this->last = before;

                            delete current;
                            this->count--;
                            return;
                        }
                    }
                    else
                    {
                        cout << "cannot find";
                        return;
                    }
                }
                else
                {
                    before = current;
                    current = current->link;
                }
            }
            if(current == NULL)
                cout << "cannot find";
        }
    }
#endif //LINKEDLIST_ORDERED_H
