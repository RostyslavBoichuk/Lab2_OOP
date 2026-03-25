/// @file DataFactory.h
/// @brief Factory for creating data.

#ifndef DATAFACTORY_H
#define DATAFACTORY_H

#include "DataManager.h"
#include <vector>

/// @class DataFactory
/// @brief Factory class for creating data vectors.
class DataFactory {
public:
    /// @brief Create a random vector.
    /// @param size Number of elements.
    /// @param min Minimum value.
    /// @param max Maximum value.
    /// @return Random vector.
    static std::vector<int> createRandom(size_t size, int min, int max);
};

#endif