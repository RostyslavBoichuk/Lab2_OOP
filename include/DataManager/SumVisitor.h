/// @file SumVisitor.h
/// @brief Visitor that sums data.

#ifndef SUMVISITOR_H
#define SUMVISITOR_H

#include "DataVisitor.h"

/// @class SumVisitor
/// @brief Visitor implementation that sums elements.
class SumVisitor : public DataVisitor {
private:
    int sum = 0; ///< Accumulated sum.
public:
    /// @brief Visit method that adds to sum.
    /// @param data The integer to add.
    void visit(int data) override {
        sum += data;
    }
    /// @brief Get the total sum.
    /// @return The sum.
    int getSum() const { return sum; }
};

#endif