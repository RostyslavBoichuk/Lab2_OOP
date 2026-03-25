/// @file test_visitor.cpp
/// @brief Unit tests for Visitor pattern implementation.

#include "catch.hpp"
#include "../include/DataManager/DataManager.h"
#include "../include/DataManager/PrintVisitor.h"
#include "../include/DataManager/SumVisitor.h"
#include <vector>
#include <sstream>

TEST_CASE("PrintVisitor", "[visitor]") {
    DataManager& dm = DataManager::getInstance();
    dm.setData({1, 2, 3});
    PrintVisitor pv;
    std::stringstream ss;
    // Redirect cout
    auto old_buf = std::cout.rdbuf(ss.rdbuf());
    dm.accept(pv);
    std::cout.rdbuf(old_buf);
    REQUIRE(ss.str() == "1 2 3 ");
}

TEST_CASE("SumVisitor", "[visitor]") {
    DataManager& dm = DataManager::getInstance();
    dm.setData({1, 2, 3});
    SumVisitor sv;
    dm.accept(sv);
    REQUIRE(sv.getSum() == 6);
}