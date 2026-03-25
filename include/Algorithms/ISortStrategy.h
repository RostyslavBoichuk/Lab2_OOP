/// @file ISortStrategy.h
/// @brief Strategy pattern interface for sorting algorithms.

#ifndef ISORTSTRATEGY_H
#define ISORTSTRATEGY_H

#include <vector>
#include <functional>

/// @class ISortStrategy
/// @brief Abstract base class for sorting strategies.
/// Defines the interface for sorting algorithms.
class ISortStrategy {
public:
    /// @brief Sort the given vector in-place.
    /// @param data The vector to sort.
    virtual void sort(std::vector<int>& data) = 0;
    /// @brief Set callback for visualization updates.
    /// @param callback Function to call after each step.
    virtual void setCallback(std::function<void(const std::vector<int>&)> callback) {}
    /// @brief Virtual destructor.
    virtual ~ISortStrategy() = default;
};

#endif