/// @file UIObserver.h
/// @brief UI observer implementation.

#ifndef UIOBSERVER_H
#define UIOBSERVER_H

#include "Observer.h"
#include <iostream>

/// @class UIObserver
/// @brief Observer for UI updates.
class UIObserver : public Observer {
public:
    /// @brief Notify by printing update message.
    void notify() override {
        std::cout << "Updated." << std::endl;
    }
};

#endif