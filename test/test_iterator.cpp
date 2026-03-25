/// @file test_iterator.cpp
/// @brief Unit tests for Iterator pattern in DataManager.

#include "catch.hpp"
#include "../include/DataManager/DataManager.h"
#include <vector>

TEST_CASE("DataManager Iterator traversal", "[iterator]") {
    DataManager& dm = DataManager::getInstance();
    dm.setData({1, 2, 3, 4});
    std::vector<int> result;
    for(auto it = dm.begin(); it != dm.end(); ++it) {
        result.push_back(*it);
    }
    REQUIRE(result == std::vector<int>{1, 2, 3, 4});
}