/// @file TimingDecorator.h
/// @brief Timing decorator for algorithms.

#ifndef TIMINGDECORATOR_H
#define TIMINGDECORATOR_H

#include "AlgorithmDecorator.h"
#include <chrono>
#include <iostream>

/// @class TimingDecorator
/// @brief Decorator that measures execution time.
/// Overrides preSort and postSort to time the sorting.
class TimingDecorator : public AlgorithmDecorator {
private:
    std::chrono::high_resolution_clock::time_point start; ///< Start time.
public:
    /// @brief Constructor.
    /// @param algo The strategy to wrap.
    TimingDecorator(ISortStrategy* algo) : AlgorithmDecorator(algo) {}
    /// @brief Starts timing.
    void preSort() override {
        start = std::chrono::high_resolution_clock::now();
    }
    /// @brief Ends timing and prints duration.
    void postSort() override {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Algorithm executed in " << elapsed.count() << " seconds.\n";
    }
};

#endif