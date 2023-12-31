#ifndef DISPLAYARRAY_H
#define DISPLAYARRAY_H
#include "Employee.h"
#include <iostream>
using namespace std;

// Function to display elements of an array

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

void displayArray(Employee arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}
#endif // DISPLAYARRAY_H
