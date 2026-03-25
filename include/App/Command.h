/// @file Command.h
/// @brief Command pattern implementations.

#ifndef COMMAND_H
#define COMMAND_H

#include "../DataManager/DataManager.h"
#include "../DataManager/DataFactory.h"
#include "Memento.h"
#include "Observer.h"
#include <memory>

/// @class Command
/// @brief Abstract command base class.
class Command {
public:
    /// @brief Execute the command.
    virtual void execute() = 0;
    /// @brief Virtual destructor.
    virtual ~Command() = default;
};

/// @class GenerateDataCommand
/// @brief Command to generate random data.
class GenerateDataCommand : public Command {
    DataManager& dm; ///< Reference to data manager.
    std::vector<Memento>& history; ///< History of states.
    Subject& subject; ///< Subject for notifications.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    /// @param h History vector.
    /// @param s Subject reference.
    GenerateDataCommand(DataManager& d, std::vector<Memento>& h, Subject& s) : dm(d), history(h), subject(s) {}
    /// @brief Execute command.
    void execute() override;
};

/// @class BubbleSortCommand
/// @brief Command to perform bubble sort.
class BubbleSortCommand : public Command {
    DataManager& dm; ///< Reference to data manager.
    std::vector<Memento>& history; ///< History of states.
    Subject& subject; ///< Subject for notifications.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    /// @param h History vector.
    /// @param s Subject reference.
    BubbleSortCommand(DataManager& d, std::vector<Memento>& h, Subject& s) : dm(d), history(h), subject(s) {}
    /// @brief Execute command.
    void execute() override;
};

/// @class QuickSortCommand
/// @brief Command to perform quick sort.
class QuickSortCommand : public Command {
    DataManager& dm; ///< Reference to data manager.
    std::vector<Memento>& history; ///< History of states.
    Subject& subject; ///< Subject for notifications.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    /// @param h History vector.
    /// @param s Subject reference.
    QuickSortCommand(DataManager& d, std::vector<Memento>& h, Subject& s) : dm(d), history(h), subject(s) {}
    /// @brief Execute command.
    void execute() override;
};

/// @class SaveCommand
/// @brief Command to save data.
class SaveCommand : public Command {
    DataManager& dm; ///< Reference to data manager.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    SaveCommand(DataManager& d) : dm(d) {}
    /// @brief Execute command.
    void execute() override;
};

/// @class LoadCommand
/// @brief Command to load data.
class LoadCommand : public Command {
    DataManager& dm; ///< Reference to data manager.
    std::vector<Memento>& history; ///< History of states.
    Subject& subject; ///< Subject for notifications.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    /// @param h History vector.
    /// @param s Subject reference.
    LoadCommand(DataManager& d, std::vector<Memento>& h, Subject& s) : dm(d), history(h), subject(s) {}
    /// @brief Execute command.
    void execute() override;
};

/// @class InputDataCommand
/// @brief Command to input data manually.
class InputDataCommand : public Command {
    DataManager& dm; ///< Reference to data manager.
    std::vector<Memento>& history; ///< History of states.
    Subject& subject; ///< Subject for notifications.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    /// @param h History vector.
    /// @param s Subject reference.
    InputDataCommand(DataManager& d, std::vector<Memento>& h, Subject& s) : dm(d), history(h), subject(s) {}
    /// @brief Execute command.
    void execute() override;
};

#endif