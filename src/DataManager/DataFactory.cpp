/**
 * @file DataFactory.cpp
 * @brief Implementation of the DataFactory class.
 * @details Contains the implementation for creating random data vectors.
 */

#include "DataManager/DataFactory.h"
#include <cstdlib>
#include <ctime>

/// @brief Creates a vector of random integers.
/// @param size The number of elements in the vector.
/// @param min The minimum value for random numbers.
/// @param max The maximum value for random numbers.
/// @return A vector filled with random integers between min and max.
/// @details Uses std::rand() seeded with current time for randomness.
std::vector<int> DataFactory::createRandom(size_t size, int min, int max) {
    std::srand(std::time(nullptr));
    std::vector<int> res(size);
    for (size_t i=0;i<size;++i)
        res[i] = min + std::rand() % (max-min+1);
    return res;
}