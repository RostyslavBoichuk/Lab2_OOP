/// @file test_builder.cpp
/// @brief Unit tests for Builder pattern in DataManager.

#include "catch.hpp"
#include "../include/DataManager/DataBuilder.h"
#include "../include/DataManager/DataDirector.h"
#include <vector>

TEST_CASE("DataBuilder builds random data", "[builder]") {
    DataDirector director;
    director.buildRandomData(5, 1, 10);
    DataManager& dm = DataManager::getInstance();
    REQUIRE(dm.getData().size() == 5);
    for(auto x : dm.getData()) {
        REQUIRE(x >= 1);
        REQUIRE(x <= 10);
    }
}