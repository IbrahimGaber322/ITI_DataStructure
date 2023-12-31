#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *pNext;
    Node(T _data) : data(_data), pNext(nullptr) {}
    ~Node() {}
};

template <class T>
class LinkedList
{
private:
    void clearHelper(Node<T> *node)
    {
        if (node != nullptr)
        {
            clearHelper(node->pNext);
            delete node;
        }
    }

public:
    Node<T> *head;
    Node<T> *tail;
    int listSize;

    LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    void insert(T data, int index = -1)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else if (index == -1)
        {
            tail->pNext = newNode;
            tail = newNode;
        }
        else if (index > listSize || index < 0)
        {
            delete newNode;
            cout << "Invalid index";
            return;
        }
        else
        {
            Node<T> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->pNext;
            }
            newNode->pNext = current->pNext;
            current->pNext = newNode;
        }
        listSize++;
    }

    void print()
    {
        if (head == nullptr || listSize == 0)
        {
            cout << "Empty" << endl;
        }
        else
        {
            Node<T> *current = head;
            while (current != nullptr)
            {
                cout << current->data << endl;
                current = current->pNext;
            }
        }
    }

    void clear()
    {
        clearHelper(head);
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }

    void deleteAt(int index)
    {
        if (index < 0 || index >= listSize)
        {
            cout << "Invalid index" << endl;
            return;
        }

        Node<T> *current = head;
        Node<T> *previous = nullptr;

        if (index == 0)
        {
            head = head->pNext;
            if (head == nullptr)
                tail = nullptr;
            delete current;
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                previous = current;
                current = current->pNext;
            }

            previous->pNext = current->pNext;
            if (current == tail)
                tail = previous;

            delete current;
        }

        listSize--;
    }

    bool search(T value)
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
                return true;
            current = current->pNext;
        }
        return false;
    }

    ~LinkedList()
    {
        clear();
    }
};

#endif
