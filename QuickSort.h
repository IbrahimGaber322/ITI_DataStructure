#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <algorithm> // For std::swap
using namespace std;

// Function to partition the array and return the pivot index
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j < high; ++j) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at (i + 1), placing the pivot in the correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform the quick sort
template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        // Find the pivot such that elements smaller than pivot are on the left and larger are on the right
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

#endif // QUICKSORT_H


