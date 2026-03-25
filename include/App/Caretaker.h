/// @file Caretaker.h
/// @brief Caretaker for memento history.

#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <vector>

/// @class Caretaker
/// @brief Manages history of mementos.
class Caretaker {
private:
    std::vector<Memento> history; ///< History of states.
public:
    /// @brief Save a state.
    /// @param data State to save.
    void save(const std::vector<int>& data) {
        history.push_back(Memento(data));
    }
    /// @brief Get history.
    /// @return Reference to history vector.
    std::vector<Memento>& getHistory() { return history; }
};

#endif