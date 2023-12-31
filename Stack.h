#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <class T>
class Stack
{
private:
    LinkedList<T> list;

public:
    void push(T data)
    {
        list.insert(data, 0); // Insert at the beginning of the list
    }

    void pop()
    {
        list.deleteAt(0); // Remove the first element in the list
    }

    T top()
    {
        if (list.head != nullptr)
        {
            return list.head->data;
        }
        else
        {
            // You might want to handle this differently based on your application's requirements
            cerr << "Error: Stack is empty" << endl;
            exit(EXIT_FAILURE);
        }
    }

    bool isEmpty()
    {
        return list.listSize == 0;
    }

    void print()
    {
        list.print();
    }

    ~Stack()
    {
        // LinkedList's destructor will be automatically called
    }
};

#endif
