/**
 * @file Command.cpp
 * @brief Implementation of command classes for the application.
 * @details Contains execute methods for various commands like generating data, sorting, saving, loading.
 */

#include "App/Command.h"
#include "Algorithms/BubbleSort.h"
#include "Algorithms/QuickSort.h"
#include "Algorithms/TimingDecorator.h"
#include "DataManager/DataDirector.h"
#include <iostream>
#include <limits>
#include <cctype>
#include <fstream>

/// @brief Executes the generate data command.
/// @details Prompts user for size, min, max, generates random data, saves to history, notifies observers.
void GenerateDataCommand::execute() {
    size_t n;
    int min, max;

    while (true) {
        std::cout << "Size: ";
        if (!(std::cin >> n) || n == 0) {
            std::cout << "Please enter a positive integer for size.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    std::cout << "Min Max: "; std::cin >> min >> max;

    DataDirector director;
    director.buildRandomData(n, min, max);
    std::cout << "Generated data: ";
    for (auto& x : dm.getData()) std::cout << x << " ";
    std::cout << std::endl;
    history.push_back(Memento(dm.getData()));
    subject.notifyAll();
}

/// @brief Executes the bubble sort command.
/// @details Prints data before sorting, sorts with timing, prints after, saves to history, notifies.
void BubbleSortCommand::execute() {
    std::cout << "Data before sorting: ";
    for (auto& x : dm.getData()) std::cout << x << " ";
    std::cout << std::endl;

    char showSteps = 'n';
    std::cout << "Show each swap step? (Y/N): ";
    std::cin >> showSteps;

    BubbleSort b;
    if (std::tolower(showSteps) == 'y') {
        b.setCallback([](const std::vector<int>& data) {
            for (auto x : data) std::cout << x << " ";
            std::cout << std::endl;
        });
    }

    TimingDecorator dec(&b);
    dec.sort(dm.getData());

    std::cout << "Data after sorting: ";
    for (auto& x : dm.getData()) std::cout << x << " ";
    std::cout << std::endl;
    history.push_back(Memento(dm.getData()));
    subject.notifyAll();
}

/// @brief Executes the quick sort command.
/// @details Similar to bubble sort but uses QuickSort algorithm.
void QuickSortCommand::execute() {
    std::cout << "Data before sorting: ";
    for (auto& x : dm.getData()) std::cout << x << " ";
    std::cout << std::endl;

    char showSteps = 'n';
    std::cout << "Show each swap step? (Y/N): ";
    std::cin >> showSteps;

    QuickSort q;
    if (std::tolower(showSteps) == 'y') {
        q.setCallback([](const std::vector<int>& data) {
            for (auto x : data) std::cout << x << " ";
            std::cout << std::endl;
        });
    }

    TimingDecorator dec(&q);
    dec.sort(dm.getData());

    std::cout << "Data after sorting: ";
    for (auto& x : dm.getData()) std::cout << x << " ";
    std::cout << std::endl;
    history.push_back(Memento(dm.getData()));
    subject.notifyAll();
}

/// @brief Executes the save command.
/// @details Prompts for filename, checks if exists, saves data.
void SaveCommand::execute() {
    std::string filename;
    std::cout << "Filename: ";
    std::cin >> filename;
    std::ifstream checkFile(filename);
    if (checkFile.is_open()) {
        checkFile.close();
        char confirm;
        std::cout << "File exists. Overwrite? (Y/N): ";
        std::cin >> confirm;
        if (std::tolower(confirm) != 'y') {
            std::cout << "Enter new filename: ";
            std::cin >> filename;
        }
    }
    dm.save(filename);
}

/// @brief Executes the load command.
/// @details Prompts for filename, loads data if possible, saves to history, notifies.
void LoadCommand::execute() {
    std::string filename; std::cout << "Filename: "; std::cin >> filename;
    if (dm.load(filename)) {
        std::cout << "Loaded data: ";
        for (auto& x : dm.getData()) std::cout << x << " ";
        std::cout << std::endl;
        history.push_back(Memento(dm.getData()));
        subject.notifyAll();
    } else {
        std::cout << "Failed to load data from file." << std::endl;
    }
}

/// @brief Executes the input data command.
/// @details Reads numbers from input until non-number, sets data, saves to history, notifies.
void InputDataCommand::execute() {
    std::vector<int> data;
    std::cout << "Enter numbers separated by spaces (end with non-number): ";
    int num;
    while (std::cin >> num) {
        data.push_back(num);
    }
    std::cin.clear(); // Clear error state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore rest of line
    dm.setData(data);
    std::cout << "Data entered: ";
    for (auto& x : data) std::cout << x << " ";
    std::cout << std::endl;
    history.push_back(Memento(data));
    subject.notifyAll();
}