#ifndef SORTING_H
#define SORTING_H

#include<iostream>
using namespace std;

class Sorting
{
public:
    virtual bool Sort_Algorithm(int a, int b) = 0;
};

class SortAsc : public Sorting
{
public:
    bool Sort_Algorithm(int a, int b)
    {
        return b < a;
    }
};

class SortDesc : public Sorting
{
public:
    bool Sort_Algorithm(int a, int b)
    {
        return a < b;
    }
};

#endif // SORTING_H
