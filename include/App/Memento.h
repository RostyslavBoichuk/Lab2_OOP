/// @file Memento.h
/// @brief Memento pattern for state snapshots.

#ifndef MEMENTO_H
#define MEMENTO_H

#include <vector>

/// @class Memento
/// @brief Stores state of data.
/// Implements prototype pattern with clone method.
class Memento {
private:
    std::vector<int> state; ///< Stored state.
public:
    /// @brief Constructor.
    /// @param s State to store.
    Memento(const std::vector<int>& s) : state(s) {}
    /// @brief Get the stored state.
    /// @return Copy of state.
    std::vector<int> getState() const { return state; }
    /// @brief Clone this memento.
    /// @return New memento with same state.
    Memento* clone() const { return new Memento(state); }
};

#endif
