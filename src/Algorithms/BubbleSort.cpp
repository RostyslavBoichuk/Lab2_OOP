/**
 * @file BubbleSort.cpp
 * @brief Implementation of the BubbleSort algorithm.
 * @details Contains the doSort method that performs bubble sort with intermediate output.
 */

#include "Algorithms/BubbleSort.h"
#include <cstddef>
#include <iostream>

/// @brief Performs the bubble sort algorithm on the given data.
/// @param data The vector of integers to sort in-place.
/// @details Implements bubble sort with O(n^2) time complexity.
/// Calls callback after each swap for visualization.
void BubbleSort::doSort(std::vector<int>& data) {
    size_t n = data.size();
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (data[j] > data[j+1]) {
                std::swap(data[j], data[j+1]);
                if (callback) callback(data);
            }
        }
    }
}