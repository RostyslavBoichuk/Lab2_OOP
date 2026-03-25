/**
 * @file GUICommand.cpp
 * @brief Implementation of GUI-specific command classes.
 * @details Contains execute methods for GUI commands that work without console I/O.
 */

#include "App/GUICommand.h"
#include "Algorithms/BubbleSort.h"
#include "Algorithms/QuickSort.h"
#include "Algorithms/TimingDecorator.h"
#include "DataManager/DataDirector.h"
#include <iostream>
#include <fstream>

/// @brief Executes the GUI generate data command.
/// @details Uses default values to generate random data, saves to history, notifies observers.
void GUIGenerateDataCommand::execute() {
    DataDirector director;
    director.buildRandomData(defaultSize, defaultMin, defaultMax);
    history.push_back(Memento(dm.getData()));
    subject.notifyAll();
}

/// @brief Executes the GUI bubble sort command.
/// @details Sorts with timing and callback for visualization, saves to history, notifies.
void GUIBubbleSortCommand::execute() {
    BubbleSort b;
    b.setCallback(callback);
    TimingDecorator dec(&b);
    dec.sort(dm.getData());
    history.push_back(Memento(dm.getData()));
    subject.notifyAll();
}

/// @brief Executes the GUI quick sort command.
/// @details Similar to bubble sort but uses QuickSort algorithm.
void GUIQuickSortCommand::execute() {
    QuickSort q;
    q.setCallback(callback);
    TimingDecorator dec(&q);
    dec.sort(dm.getData());
    history.push_back(Memento(dm.getData()));
    subject.notifyAll();
}

/// @brief Executes the GUI save command.
/// @details Prompts for filename using a simple default.
void GUISaveCommand::execute() {
    std::string filename = "data.txt";
    dm.save(filename);
}

/// @brief Executes the GUI load command.
/// @details Loads from default filename if possible, saves to history, notifies.
void GUILoadCommand::execute() {
    std::string filename = "data.txt";
    if (dm.load(filename)) {
        history.push_back(Memento(dm.getData()));
        subject.notifyAll();
    }
}

/// @brief Executes the GUI input data command.
/// @details Sets default data, saves to history, notifies.
void GUIInputDataCommand::execute() {
    dm.setData(defaultData);
    history.push_back(Memento(dm.getData()));
    subject.notifyAll();
}