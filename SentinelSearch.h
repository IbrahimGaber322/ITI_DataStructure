// sentinel_search.h

#ifndef SENTINEL_SEARCH_H
#define SENTINEL_SEARCH_H

// Function to perform sentinel search
int sentinelSearch(int arr[], int size, int target){
    // Save the last element and set it as the sentinel
    int lastElement = arr[size - 1];
    arr[size - 1] = target;

    int i = 0;
    while (arr[i] != target) {
        i++;
    }

    // Restore the original last element
    arr[size - 1] = lastElement;

    // If the index is less than the original size, the target is found
    if (i < size - 1) {
        return i;
    } else {
        // Target not found
        return -1;
    }
};

#endif // SENTINEL_SEARCH_H
