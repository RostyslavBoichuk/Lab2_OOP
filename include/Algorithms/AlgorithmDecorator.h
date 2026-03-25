/// @file AlgorithmDecorator.h
/// @brief Decorator pattern for algorithms.

#ifndef ALGORITHMDECORATOR_H
#define ALGORITHMDECORATOR_H

#include "ISortStrategy.h"
#include <chrono>
#include <iostream>

/// @class AlgorithmDecorator
/// @brief Base decorator for sorting strategies.
/// Implements template method with pre and post hooks.
class AlgorithmDecorator : public ISortStrategy {
protected:
    ISortStrategy* wrapped; ///< Wrapped strategy.
    std::function<void(const std::vector<int>&)> callback; ///< Callback for updates.
    /// @brief Pre-sort hook.
    virtual void preSort() {}
    /// @brief Post-sort hook.
    virtual void postSort() {}
public:
    /// @brief Constructor.
    /// @param algo The strategy to wrap.
    AlgorithmDecorator(ISortStrategy* algo) : wrapped(algo) {}
    /// @brief Sort method with hooks.
    /// @param data The vector to sort.
    void sort(std::vector<int>& data) override {
        preSort();
        wrapped->sort(data);
        postSort();
    }
    /// @brief Set callback for visualization.
    /// @param cb Callback function.
    void setCallback(std::function<void(const std::vector<int>&)> cb) override {
        callback = cb;
        wrapped->setCallback(cb);
    }
};

#endif