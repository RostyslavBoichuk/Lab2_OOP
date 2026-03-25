/// @file SortTemplate.h
/// @brief Template method pattern for sorting.

#ifndef SORTTEMPLATE_H
#define SORTTEMPLATE_H

#include "ISortStrategy.h"

/// @class SortTemplate
/// @brief Base class implementing template method for sorting.
/// Provides hooks for pre and post sort operations.
class SortTemplate : public ISortStrategy {
protected:
    std::function<void(const std::vector<int>&)> callback; ///< Callback for updates.
public:
    /// @brief Template method that calls preSort, doSort, postSort.
    /// @param data The vector to sort.
    void sort(std::vector<int>& data) override final {
        preSort();
        doSort(data);
        postSort();
    }
    /// @brief Set callback for visualization.
    /// @param cb Callback function.
    void setCallback(std::function<void(const std::vector<int>&)> cb) override {
        callback = cb;
    }
    /// @brief Hook for pre-sort operations.
    virtual void preSort() {}
    /// @brief Pure virtual method for actual sorting.
    /// @param data The vector to sort.
    virtual void doSort(std::vector<int>& data) = 0;
    /// @brief Hook for post-sort operations.
    virtual void postSort() {}
};

#endif