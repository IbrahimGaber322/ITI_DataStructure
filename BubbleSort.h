
#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "Sorting.h"
#include "Employee.h"
#include <iostream>

class BubbleSort
{
public:
    virtual bool Sort_Algorithm(int a, int b) = 0;
};

class AscAlgorithm : public BubbleSort
{
public:
    bool Sort_Algorithm(int a, int b) override
    {
        return a > b;
    }
};

class DescAlgorithm : public BubbleSort
{
public:
    bool Sort_Algorithm(int a, int b) override
    {
        return a < b;
    }
};

void bubbleSort(int arr[], int size, Sorting *pSort)
{
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (pSort->Sort_Algorithm(arr[i], arr[i + 1]))
            {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
}

void bubbleSort(Employee arr[], int size, Sorting *pSort)
{
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (pSort->Sort_Algorithm(arr[i].getId(), arr[i + 1].getId()))
            {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
}

void bubbleSort(int arr[], int size, bool (*pFunc)(int a, int b))
{
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (pFunc(arr[i], arr[i + 1]))
            {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
}

#endif // BUBBLESORT_H
