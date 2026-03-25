/**
 * @file ConsoleApp.cpp
 * @brief Implementation of the ConsoleApp class.
 * @details Contains the constructor and run method for the console application.
 */

#include "App/ConsoleApp.h"
#include <limits>

/// @brief Constructor for ConsoleApp.
/// @details Initializes commands, adds observers (logging and UI).
ConsoleApp::ConsoleApp() {
    DataManager& dm = DataManager::getInstance();
    commands.push_back(std::make_unique<GenerateDataCommand>(dm, caretaker.getHistory(), *this));
    commands.push_back(std::make_unique<BubbleSortCommand>(dm, caretaker.getHistory(), *this));
    commands.push_back(std::make_unique<QuickSortCommand>(dm, caretaker.getHistory(), *this));
    commands.push_back(std::make_unique<SaveCommand>(dm));
    commands.push_back(std::make_unique<LoadCommand>(dm, caretaker.getHistory(), *this));
    commands.push_back(std::make_unique<InputDataCommand>(dm, caretaker.getHistory(), *this));
    addObserver(new LoggingObserver());
    addObserver(new UIObserver());
}

/// @brief Runs the main application loop.
/// @details Displays menu, reads user choice, executes corresponding command until exit.
void ConsoleApp::run() {
    int choice = -1;
    do {
        std::cout << "\n1. Generate Random Data\n2. Bubble Sort\n3. Quick Sort\n4. Save Data\n5. Load Data\n6. Input Custom Data\n0. Exit\nChoice: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            choice = -1;
            continue;
        }
        if (choice >= 1 && choice <= 6) {
            commands[choice - 1]->execute();
        } else if (choice != 0) {
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}