#ifndef DATAMANAGER_H
#define DATAMANAGER_H

/// @file DataManager.h
/// @brief Header for DataManager singleton class.

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "DataVisitor.h"

/// @class DataManager
/// @brief Singleton class for managing application data.
/// Provides functionality to store, retrieve, save, and load integer data.
/// Implements Iterator and Visitor patterns.
class DataManager {
private:
    std::vector<int> data; ///< The data vector.
    DataManager() = default; ///< Private constructor for singleton.
public:
    /// @brief Iterator class for traversing data.
    class DataIterator {
    private:
        std::vector<int>::iterator it; ///< Internal iterator.
    public:
        /// @brief Constructor.
        /// @param i Iterator to initialize with.
        DataIterator(std::vector<int>::iterator i) : it(i) {}
        /// @brief Dereference operator.
        /// @return Reference to current element.
        int& operator*() { return *it; }
        /// @brief Increment operator.
        /// @return Reference to this iterator.
        DataIterator& operator++() { ++it; return *this; }
        /// @brief Inequality operator.
        /// @param other Iterator to compare.
        /// @return True if not equal.
        bool operator!=(const DataIterator& other) const { return it != other.it; }
    };
    /// @brief Get singleton instance.
    /// @return Reference to the singleton instance.
    static DataManager& getInstance() {
        static DataManager instance;
        return instance;
    }
    /// @brief Set the data.
    /// @param d Vector of integers to set.
    void setData(const std::vector<int>& d) { data = d; }
    /// @brief Get the data.
    /// @return Reference to the data vector.
    std::vector<int>& getData() { return data; }
    /// @brief Get begin iterator.
    /// @return DataIterator to beginning.
    DataIterator begin() { return DataIterator(data.begin()); }
    /// @brief Get end iterator.
    /// @return DataIterator to end.
    DataIterator end() { return DataIterator(data.end()); }
    /// @brief Accept a visitor.
    /// @param v Visitor to accept.
    void accept(DataVisitor& v) { for(auto x : data) v.visit(x); }
    /// @brief Save data to file.
    /// @param filename File to save to.
    void save(const std::string& filename);
    /// @brief Load data from file.
    /// @param filename File to load from.
    /// @return True if load was successful.
    bool load(const std::string& filename);
};

#endif