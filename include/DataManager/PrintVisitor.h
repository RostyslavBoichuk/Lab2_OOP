/// @file PrintVisitor.h
/// @brief Visitor that prints data.

#ifndef PRINTVISITOR_H
#define PRINTVISITOR_H

#include "DataVisitor.h"
#include <iostream>

/// @class PrintVisitor
/// @brief Visitor implementation that prints each element.
class PrintVisitor : public DataVisitor {
public:
    /// @brief Visit method that prints the data.
    /// @param data The integer to print.
    void visit(int data) override {
        std::cout << data << " ";
    }
};

#endif