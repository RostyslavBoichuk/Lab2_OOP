/// @file Observer.h
/// @brief Observer pattern implementation.

#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <functional>

/// @class Observer
/// @brief Abstract observer base class.
class Observer {
public:
    /// @brief Notify method called by subject.
    virtual void notify() = 0;
};

/// @class Subject
/// @brief Subject that manages observers.
class Subject {
    std::vector<Observer*> observers; ///< List of observers.
public:
    /// @brief Add an observer.
    /// @param o Pointer to observer.
    void addObserver(Observer* o) { observers.push_back(o); }
    /// @brief Notify all observers.
    void notifyAll() { for (auto o : observers) o->notify(); }
};

#endif