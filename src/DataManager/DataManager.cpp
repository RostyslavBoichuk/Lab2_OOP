/**
 * @file DataManager.cpp
 * @brief Implementation of the DataManager singleton class.
 * @details This file contains the implementation of methods for saving and loading data.
 */

#include "DataManager/DataManager.h"

/// @brief Saves the current data to a file.
/// @param filename The name of the file to save data to.
/// @details Writes each integer in the data vector to the file, separated by spaces.
/// If the file cannot be opened, an error message is printed to stderr.
void DataManager::save(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) { std::cerr << "Cannot open file to save\n"; return; }
    for (int val : data) file << val << " ";
}

/// @brief Loads data from a file.
/// @param filename The name of the file to load data from.
/// @return True if the file was successfully loaded, false otherwise.
/// @details Clears the current data and reads integers from the file.
/// Assumes the file contains space-separated integers.
bool DataManager::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return false;
    data.clear();
    int val;
    while (file >> val) data.push_back(val);
    return true;
}