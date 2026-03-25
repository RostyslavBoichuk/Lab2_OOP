/// @file DataBuilder.h
/// @brief Builder pattern for data construction.

#ifndef DATABUILDER_H
#define DATABUILDER_H

#include "DataManager.h"

/// @class DataBuilder
/// @brief Builder for constructing data in DataManager.
class DataBuilder {
private:
    std::vector<int> temp; ///< Temporary data.
public:
    /// @brief Add a single value.
    /// @param value Value to add.
    /// @return Reference to this builder.
    DataBuilder& add(int value) { temp.push_back(value); return *this; }
    /// @brief Add a range of values.
    /// @param values Vector to add.
    /// @return Reference to this builder.
    DataBuilder& addRange(const std::vector<int>& values) { temp.insert(temp.end(), values.begin(), values.end()); return *this; }
    /// @brief Build and set data in DataManager.
    void build() { DataManager::getInstance().setData(temp); }
};

#endif