/// @file LoggingObserver.h
/// @brief Logging observer implementation.

#ifndef LOGGINGOBSERVER_H
#define LOGGINGOBSERVER_H

#include "Observer.h"
#include <iostream>

/// @class LoggingObserver
/// @brief Observer that logs updates.
class LoggingObserver : public Observer {
public:
    /// @brief Notify by printing update message.
    void notify() override {
        std::cout << "Updated." << std::endl;
    }
};

#endif