/// @file ConsoleApp.h
/// @brief Console application class.

#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H

#include "../Algorithms/ISortStrategy.h"
#include "../Algorithms/BubbleSort.h"
#include "../Algorithms/QuickSort.h"
#include "../Algorithms/AlgorithmDecorator.h"
#include "../DataManager/DataManager.h"
#include "../DataManager/DataFactory.h"
#include "Command.h"
#include "Memento.h"
#include "Observer.h"
#include "Caretaker.h"
#include "LoggingObserver.h"
#include "UIObserver.h"
#include <memory>
#include <vector>
#include <iostream>

/// @class ConsoleApp
/// @brief Main console application.
/// Inherits from Subject to notify observers.
class ConsoleApp : public Subject {
private:
    std::vector<std::unique_ptr<Command>> commands; ///< List of commands.
    Caretaker caretaker; ///< Caretaker for history.
public:
    /// @brief Constructor.
    ConsoleApp();
    /// @brief Run the application loop.
    void run();
};

#endif