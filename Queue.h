#ifndef QUEUE_H
#define QUEUE_H

#include "Stack.h"

template <class T>
class Queue
{
private:
    Stack<T> inStack;
    Stack<T> outStack;

public:
    void enqueue(T data)
    {
        // Push the data onto the input stack
        inStack.push(data);
    }

    void dequeue()
    {
        // If the output stack is empty, transfer elements from the input stack
        if (outStack.isEmpty())
        {
            while (!inStack.isEmpty())
            {
                T topElement = inStack.top();
                inStack.pop();
                outStack.push(topElement);
            }
        }

        // Pop the element from the output stack
        if (!outStack.isEmpty())
        {
            outStack.pop();
        }
        else
        {
            cerr << "Error: Queue is empty" << endl;
            exit(EXIT_FAILURE);
        }
    }

    T front()
    {
        // If the output stack is empty, transfer elements from the input stack
        if (outStack.isEmpty())
        {
            while (!inStack.isEmpty())
            {
                T topElement = inStack.top();
                inStack.pop();
                outStack.push(topElement);
            }
        }

        // Return the front element without popping it
        if (!outStack.isEmpty())
        {
            return outStack.top();
        }
        else
        {
            cerr << "Error: Queue is empty" << endl;
            exit(EXIT_FAILURE);
        }
    }

    bool isEmpty()
    {
        return inStack.isEmpty() && outStack.isEmpty();
    }

    void print()
    {
        // Print the elements in the queue (based on the order in the outStack and inStack)
        outStack.print();
        inStack.print();
    }

    ~Queue()
    {
        // Stack destructors (inStack and outStack) will be automatically called
    }
};

#endif
