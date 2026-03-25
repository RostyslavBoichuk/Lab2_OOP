/// @file DataDirector.h
/// @brief Director for data building.

#ifndef DATADIRECTOR_H
#define DATADIRECTOR_H

#include "DataBuilder.h"
#include "DataFactory.h"

/// @class DataDirector
/// @brief Director that uses builder and factory to construct data.
class DataDirector {
private:
    DataBuilder builder; ///< Builder instance.
public:
    /// @brief Build random data.
    /// @param n Number of elements.
    /// @param min Minimum value.
    /// @param max Maximum value.
    void buildRandomData(size_t n, int min, int max) {
        auto data = DataFactory::createRandom(n, min, max);
        builder.addRange(data).build();
    }
    // Could add more build methods
};

#endif