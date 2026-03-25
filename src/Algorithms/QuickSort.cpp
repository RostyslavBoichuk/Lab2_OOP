/**
 * @file QuickSort.cpp
 * @brief Implementation of the QuickSort algorithm.
 * @details Contains the doSort method and helper functions for quicksort.
 */

#include "Algorithms/QuickSort.h"
#include <iostream>

/// @brief Initiates the quicksort algorithm.
/// @param data The vector of integers to sort in-place.
/// @details Calls the recursive quicksort function if data is not empty.
void QuickSort::doSort(std::vector<int>& data) {
    if (!data.empty())
        quicksort(data, 0, data.size()-1);
}

/// @brief Recursive function to perform quicksort.
/// @param data The vector to sort.
/// @param low The starting index of the subarray.
/// @param high The ending index of the subarray.
/// @details Recursively sorts the subarrays divided by the partition.
void QuickSort::quicksort(std::vector<int>& data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quicksort(data, low, pi-1);
        quicksort(data, pi+1, high);
    }
}

/// @brief Partitions the array and returns the pivot index.
/// @param data The vector to partition.
/// @param low The starting index.
/// @param high The ending index.
/// @return The index of the pivot after partitioning.
/// @details Uses the last element as pivot, rearranges elements,
/// and calls callback after swaps for visualization.
int QuickSort::partition(std::vector<int>& data, int low, int high) {
    int pivot = data[high];
    int i = low-1;
    for (int j = low; j < high; ++j) {
        if (data[j] < pivot) {
            ++i;
            std::swap(data[i], data[j]);
            if (callback) callback(data);
        }
    }
    std::swap(data[i+1], data[high]);
    if (callback) callback(data);
    return i+1;
}