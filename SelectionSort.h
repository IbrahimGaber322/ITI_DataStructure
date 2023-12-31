#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <algorithm> // For std::swap
using namespace std;

template <typename T>
void selectionSort(T arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        int minIndex = i;

        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

#endif // SELECTIONSORT_H
