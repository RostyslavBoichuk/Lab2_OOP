/// @file test_sorting.cpp
/// @brief Unit tests for sorting algorithms.

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/Algorithms/BubbleSort.h"
#include "../include/Algorithms/QuickSort.h"
#include "../include/Algorithms/TimingDecorator.h"
#include <vector>
#include <algorithm>

TEST_CASE("BubbleSort sorts correctly", "[sorting]") {
    BubbleSort sorter;
    TimingDecorator dec(&sorter);
    std::vector<int> data = {3, 1, 4, 1, 5};
    dec.sort(data);
    REQUIRE(std::is_sorted(data.begin(), data.end()));
}

TEST_CASE("QuickSort sorts correctly", "[sorting]") {
    QuickSort sorter;
    TimingDecorator dec(&sorter);
    std::vector<int> data = {3, 1, 4, 1, 5};
    dec.sort(data);
    REQUIRE(std::is_sorted(data.begin(), data.end()));
}

TEST_CASE("Sorting empty vector", "[sorting]") {
    BubbleSort sorter;
    TimingDecorator dec(&sorter);
    std::vector<int> data;
    dec.sort(data);
    REQUIRE(data.empty());
}

#include <chrono>

TEST_CASE("Sorting large data performance", "[sorting]") {
    std::vector<int> largeData(1000);
    for(int i = 0; i < 1000; i++) largeData[i] = 1000 - i;
    BubbleSort sorter;
    TimingDecorator dec(&sorter);
    auto start = std::chrono::high_resolution_clock::now();
    dec.sort(largeData);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    REQUIRE(std::is_sorted(largeData.begin(), largeData.end()));
    REQUIRE(elapsed.count() < 1.0); // Should be fast enough
}