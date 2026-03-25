/// @file QuickSort.h
/// @brief Quick sort implementation.

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortTemplate.h"

/// @class QuickSort
/// @brief Implements quick sort algorithm.
/// Inherits from SortTemplate.
class QuickSort : public SortTemplate {
public:
    /// @brief Performs quick sort on the data.
    /// @param data The vector to sort.
    void doSort(std::vector<int>& data) override;
private:
    /// @brief Recursive quicksort function.
    /// @param data The vector.
    /// @param low Low index.
    /// @param high High index.
    void quicksort(std::vector<int>& data, int low, int high);
    /// @brief Partition function for quicksort.
    /// @param data The vector.
    /// @param low Low index.
    /// @param high High index.
    /// @return Pivot index.
    int partition(std::vector<int>& data, int low, int high);
};

#endif