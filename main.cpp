/// @file main.cpp
/// @brief Main entry point for the Algorithm Visualizer application.
/// @mainpage Algorithm Visualizer
/// This application demonstrates the use of various design patterns in C++.
/// Implemented patterns include Singleton, Builder, Factory Method, Strategy,
/// Decorator, Observer, Memento, Command, Template Method, Iterator, Prototype, Visitor.
/// The application allows generating random data, sorting with different algorithms,
/// saving/loading data, and observing changes.

#include "include/App/ConsoleApp.h"

/// @brief Main function.
/// @return Exit code.
int main() {
    ConsoleApp app;
    app.run();

    return 0;
}