# Algorithm Visualizer

A C++ console application that demonstrates various design patterns for visualizing sorting algorithms.

## Features

- **Design Patterns Implemented:**
  - Singleton, Builder, Factory Method, Strategy, Decorator, Observer, Memento, Command, Template Method, Iterator, Prototype, Visitor

- **Sorting Algorithms:**
  - Bubble Sort
  - Quick Sort
  - With timing decorators

- **Data Management:**
  - Generate random data
  - Manual data input
  - Save/Load data to/from files
  - Undo/Redo with Memento pattern

## Building

The project uses g++ with C++14 standard. Run the build task in VS Code or use:

```bash
g++ -std=c++14 -static -Iinclude -o AlgoVisualizer2.exe main.cpp \
    src/Algorithms/AlgorithmDecorator.cpp \
    src/Algorithms/BubbleSort.cpp \
    src/Algorithms/QuickSort.cpp \
    src/App/Command.cpp \
    src/App/ConsoleApp.cpp \
    src/App/Memento.cpp \
    src/App/Observer.cpp \
    src/DataManager/DataBuilder.cpp \
    src/DataManager/DataFactory.cpp \
    src/DataManager/DataManager.cpp
```

## Running

```bash
./AlgoVisualizer2.exe
```

The console application provides a menu with the following options:
1. Generate Random Data (prompts for a positive size, min, max)
2. Bubble Sort (optionally displays each swap step)
3. Quick Sort (optionally displays each swap step)
4. Save Data
5. Load Data
6. Input Custom Data
0. Exit

## Testing

Run the test suite:
```bash
g++ -std=c++14 -static -Iinclude -Itest -o test_runner.exe \
    test/test_sorting.cpp test/test_datamanager.cpp test/test_visitor.cpp \
    test/test_memento.cpp test/test_iterator.cpp test/test_builder.cpp \
    src/Algorithms/AlgorithmDecorator.cpp src/Algorithms/BubbleSort.cpp \
    src/Algorithms/QuickSort.cpp \
    src/DataManager/DataBuilder.cpp src/DataManager/DataFactory.cpp \
    src/DataManager/DataManager.cpp
./test_runner.exe
```

## Architecture

- **ConsoleApp**: Handles console-based interaction
- **DataManager**: Singleton for data storage and operations
- **Sorting Strategies**: Pluggable sorting algorithms with decorator support
- **Command Pattern**: Encapsulates user actions
- **Observer Pattern**: Notifies components of changes
- **Memento Pattern**: Provides undo functionality