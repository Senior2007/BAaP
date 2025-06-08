#include "BinaryOperation.h"
#include <stdexcept>

BinaryOperation::BinaryOperation(Expression* left, char operation, Expression* right) : left(left), operation(operation), right(right) {}

BinaryOperation::~BinaryOperation() {
    delete left;
    delete right;
}

double BinaryOperation::evaluate() const {
    double leftValue = left->evaluate();
    double rightValue = right->evaluate();
    switch (operation) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: throw std::invalid_argument("Unknown operation");
    }
}