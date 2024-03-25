//
// Created by enes4 on 3/25/2024.
//

#ifndef LINKEDLIST_UNORDERED_H
#define LINKEDLIST_UNORDERED_H

#include "LL.h"

        template <class T>
        class unorderedLinkedList : public LL<T>
                {
                public:
        void insertFirst(T &item);
        void insertLast(T &item);

            node<T> *search(T &);

            void deleteNode(T &);
        };

        template <class T>
        void unorderedLinkedList<T>::insertFirst(T& item)
        {
            node<T>* newNode = new node<T>;
            newNode->info = item;
            newNode->link = NULL;

            if(this->head == NULL)
            {
                this->head = newNode;
                this->last = newNode;
            }

            else
            {
                newNode->link = this->head;
                this->head = newNode;
            }
            this->count++;
        }

        template <class T>
        void unorderedLinkedList<T>::insertLast(T &item)
        {
            node<T>* newNode = new node<T>;
            newNode->info = item;
            newNode->link = NULL;

            if(this->head == NULL)
            {
                this->head = newNode;
                this->last = newNode;
            }

            else
            {
                this->last->link = newNode;
                this->last = newNode;
            }
            this->count++;
        }

        template <class T>
        node<T>* unorderedLinkedList<T>::search(T &item)
        {
            if(this->head == NULL)
            {
                cout << "Cannot search in empty list.\n";
            }
            else
            {
                node<T>* current = this->head;

                while(current != NULL)
                {
                    if(current->info == item)
                        return current;
                    else
                        current = current->link;
                }
            }
            return NULL;
        }

        template <class T>
        void unorderedLinkedList<T>::deleteNode(T &item)
        {
            node<T> *current,*before;
            current = this->head->link;
            before = this->head;

            if(this->head->info == item)
            {
                this->head = this->head->link;
                if(this->head  == NULL)
                    this->last = NULL;
                delete before;
            }
            else
            {
                while(current !=NULL)
                {
                    if(current->info == item)
                    {
                        if(current == this->last)
                        {
                            before->link = NULL;
                            this->last = before;
                            delete current;
                            break;
                        }
                        else
                        {
                            before->link = current->link;
                            delete current;
                            break;
                        }
                    }
                    current = current->link;
                    before = before->link;
                }
            }
        }







#endif //LINKEDLIST_UNORDERED_H
