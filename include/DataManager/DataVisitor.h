/// @file DataVisitor.h
/// @brief Visitor pattern for data operations.

#ifndef DATAVISITOR_H
#define DATAVISITOR_H

/// @class DataVisitor
/// @brief Abstract visitor for data elements.
class DataVisitor {
public:
    /// @brief Visit a data element.
    /// @param data The integer to visit.
    virtual void visit(int data) = 0;
    /// @brief Virtual destructor.
    virtual ~DataVisitor() = default;
};

#endif