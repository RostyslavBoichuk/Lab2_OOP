/// @file GUICommand.h
/// @brief GUI-specific command pattern implementations.

#ifndef GUICOMMAND_H
#define GUICOMMAND_H

#include "../DataManager/DataManager.h"
#include "../DataManager/DataFactory.h"
#include "Memento.h"
#include "Observer.h"
#include <memory>
#include <vector>
#include <string>

/// @class GUICommand
/// @brief Abstract GUI command base class.
class GUICommand {
public:
    /// @brief Execute the command.
    virtual void execute() = 0;
    /// @brief Virtual destructor.
    virtual ~GUICommand() = default;
};

/// @class GUIGenerateDataCommand
/// @brief GUI command to generate random data.
class GUIGenerateDataCommand : public GUICommand {
    DataManager& dm; ///< Reference to data manager.
    std::vector<Memento>& history; ///< History of states.
    Subject& subject; ///< Subject for notifications.
    size_t defaultSize; ///< Default data size.
    int defaultMin; ///< Default min value.
    int defaultMax; ///< Default max value.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    /// @param h History vector.
    /// @param s Subject reference.
    /// @param size Default size.
    /// @param min Default min.
    /// @param max Default max.
    GUIGenerateDataCommand(DataManager& d, std::vector<Memento>& h, Subject& s,
                          size_t size = 20, int min = 1, int max = 100)
        : dm(d), history(h), subject(s), defaultSize(size), defaultMin(min), defaultMax(max) {}
    /// @brief Execute command.
    void execute() override;
};

/// @class GUIBubbleSortCommand
/// @brief GUI command to perform bubble sort.
class GUIBubbleSortCommand : public GUICommand {
    DataManager& dm; ///< Reference to data manager.
    std::vector<Memento>& history; ///< History of states.
    Subject& subject; ///< Subject for notifications.
    std::function<void(const std::vector<int>&)> callback; ///< Update callback.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    /// @param h History vector.
    /// @param s Subject reference.
    /// @param cb Update callback.
    GUIBubbleSortCommand(DataManager& d, std::vector<Memento>& h, Subject& s,
                        std::function<void(const std::vector<int>&)> cb)
        : dm(d), history(h), subject(s), callback(cb) {}
    /// @brief Execute command.
    void execute() override;
};

/// @class GUIQuickSortCommand
/// @brief GUI command to perform quick sort.
class GUIQuickSortCommand : public GUICommand {
    DataManager& dm; ///< Reference to data manager.
    std::vector<Memento>& history; ///< History of states.
    Subject& subject; ///< Subject for notifications.
    std::function<void(const std::vector<int>&)> callback; ///< Update callback.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    /// @param h History vector.
    /// @param s Subject reference.
    /// @param cb Update callback.
    GUIQuickSortCommand(DataManager& d, std::vector<Memento>& h, Subject& s,
                       std::function<void(const std::vector<int>&)> cb)
        : dm(d), history(h), subject(s), callback(cb) {}
    /// @brief Execute command.
    void execute() override;
};

/// @class GUISaveCommand
/// @brief GUI command to save data.
class GUISaveCommand : public GUICommand {
    DataManager& dm; ///< Reference to data manager.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    GUISaveCommand(DataManager& d) : dm(d) {}
    /// @brief Execute command.
    void execute() override;
};

/// @class GUILoadCommand
/// @brief GUI command to load data.
class GUILoadCommand : public GUICommand {
    DataManager& dm; ///< Reference to data manager.
    std::vector<Memento>& history; ///< History of states.
    Subject& subject; ///< Subject for notifications.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    /// @param h History vector.
    /// @param s Subject reference.
    GUILoadCommand(DataManager& d, std::vector<Memento>& h, Subject& s)
        : dm(d), history(h), subject(s) {}
    /// @brief Execute command.
    void execute() override;
};

/// @class GUIInputDataCommand
/// @brief GUI command to input custom data.
class GUIInputDataCommand : public GUICommand {
    DataManager& dm; ///< Reference to data manager.
    std::vector<Memento>& history; ///< History of states.
    Subject& subject; ///< Subject for notifications.
    std::vector<int> defaultData; ///< Default data to use.
public:
    /// @brief Constructor.
    /// @param d DataManager reference.
    /// @param h History vector.
    /// @param s Subject reference.
    /// @param data Default data.
    GUIInputDataCommand(DataManager& d, std::vector<Memento>& h, Subject& s,
                       const std::vector<int>& data = {5, 3, 8, 1, 9, 2, 7, 4, 6})
        : dm(d), history(h), subject(s), defaultData(data) {}
    /// @brief Execute command.
    void execute() override;
};

#endif