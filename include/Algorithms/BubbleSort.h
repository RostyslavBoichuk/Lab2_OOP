/// @file BubbleSort.h
/// @brief Bubble sort implementation.

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortTemplate.h"

/// @class BubbleSort
/// @brief Implements bubble sort algorithm.
/// Inherits from SortTemplate to use template method pattern.
class BubbleSort : public SortTemplate {
public:
    /// @brief Performs bubble sort on the data.
    /// @param data The vector to sort.
    void doSort(std::vector<int>& data) override;
};

#endif