/// @file test_memento.cpp
/// @brief Unit tests for Memento pattern.

#include "catch.hpp"
#include "../include/App/Memento.h"
#include <vector>

TEST_CASE("Memento stores and retrieves state", "[memento]") {
    std::vector<int> state = {1, 2, 3};
    Memento m(state);
    REQUIRE(m.getState() == state);
}

TEST_CASE("Memento clone creates copy", "[memento]") {
    std::vector<int> state = {4, 5, 6};
    Memento m(state);
    Memento* clone = m.clone();
    REQUIRE(clone->getState() == state);
    REQUIRE(clone != &m);
    delete clone;
}