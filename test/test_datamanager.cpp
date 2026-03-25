/// @file test_datamanager.cpp
/// @brief Unit tests for DataManager class.

#include "catch.hpp"
#include "../include/DataManager/DataManager.h"
#include <vector>
#include <fstream>

TEST_CASE("DataManager Singleton", "[datamanager]") {
    DataManager& dm1 = DataManager::getInstance();
    DataManager& dm2 = DataManager::getInstance();
    REQUIRE(&dm1 == &dm2);
}

TEST_CASE("DataManager set and get data", "[datamanager]") {
    DataManager& dm = DataManager::getInstance();
    std::vector<int> data = {1, 2, 3};
    dm.setData(data);
    REQUIRE(dm.getData() == data);
}

TEST_CASE("DataManager save and load", "[datamanager]") {
    DataManager& dm = DataManager::getInstance();
    std::vector<int> data = {4, 5, 6};
    dm.setData(data);
    dm.save("test_data.txt");
    dm.setData({}); // clear
    dm.load("test_data.txt");
    REQUIRE(dm.getData() == data);
    // cleanup
    std::remove("test_data.txt");
}