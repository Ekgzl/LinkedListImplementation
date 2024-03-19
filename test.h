//
// Created by enes4 on 3/15/2024.
//

#ifndef ULINKEDLISTS_TEST_H
#define ULINKEDLISTS_TEST_H

#include <iostream>
#include <cassert>
using namespace std;


template<class T>
struct nodeType
        {
            T info;
            nodeType<T>* link;
        };

template<class T>
class linkedListType
        {
        protected:
            nodeType<T> *first,*last;
            int count;
        public:
            linkedListType();
            ~linkedListType();
            bool isEmptyList();
            int length();
            T back();
            T front();
            void destroyList();
            nodeType<T>* search(const T&);
            void insertFirst(const T&);
            void insertLast(const T&);
            void deleteNode(const T&);
            friend ostream& operator<<(ostream& os, linkedListType<T>& otherList)
            {
                    os << otherList.count;sc
                    return os;
            }
            void print();
        };


        template<class T>
        void linkedListType<T>::deleteNode(const T &item)
        {
            nodeType<T> *current,*before_current;

            if(first == nullptr)
                cout << "cannot delete fomr an empty list" << endl;

            else
            {
                if(first->info == item)
                {
                    current = first;
                    first = first->link;
                    count--;
                    if(first== nullptr)
                        last = nullptr;
                    delete current;
                }

                else
                {
                    current = first->link;
                    before_current = first;
                    while(current != nullptr)
                    {
                        if(current->info == item)
                        {
                            before_current->link = current->link;
                            count--;
                            if(last == current)
                                last = before_current;
                            delete current;
                            break;
                        }
                        else
                        current = current->link;
                    }
                    if(current == nullptr)
                        cout << "The item to be deleted is not in the list" << endl;
                }
            }

        }

        template<class T>
        void linkedListType<T>::print()
        {
            nodeType<T> *current;
            current = first;
            while(current != nullptr)
            {
                cout << " " << current->info;
                current = current->link;
            }
            delete current;
        }

        template<class T>
        void linkedListType<T>::insertFirst(const T &item)
        {
            nodeType<T> *newNode = new nodeType<T>;
            newNode->info = item;
            newNode->link = first;
            first = newNode;
            if(last == nullptr)
            last = newNode;
            count++;
        }

        template<class T>
        void linkedListType<T>::insertLast(const T &item)
        {
            nodeType<T>* newNode = new nodeType<T>;
            newNode->info = item;
            newNode->link = nullptr;
            if(first == nullptr)
                first == newNode;
            else
                last->link = newNode;
            last = newNode;
            count++;
        }

        template<class T>
        nodeType<T>*  linkedListType<T>::search(const T &otherLink)
        {
            nodeType<T> *current = first;

            if(first == nullptr)
            {
                cout << "cannot delete from an empty list" << endl;
                return nullptr;
            }


            while(current != nullptr)
            {
                if(current->info==otherLink)
                    return current;
                else
                    current = current->link;
            }
            return nullptr;
        }

        template<class T>
        T linkedListType<T>::back()
        {
            return last->info;
        }

        template<class T>
        T linkedListType<T>::front()
        {
            return first->info;
        }

        template<class T>
        bool linkedListType<T>::isEmptyList()
        {
            return (first == nullptr);
        }

        template<class T>
        int linkedListType<T>::length()
        {
            return count;
        }

        template<class T>
        linkedListType<T>::linkedListType()
        {
            first = nullptr;
            last = nullptr;
            count = 0;
        }

        template<class T>
        linkedListType<T>::~linkedListType()
        {
            destroyList();
        }

        template<class T>
        void linkedListType<T>::destroyList()
        {
            nodeType<T>* temp;

            while(first != nullptr)
            {
                temp = first;
                first = first->link;
                delete temp;
            }
            last = nullptr;
            count = 0;
        }


#endif //ULINKEDLISTS_TEST_H
