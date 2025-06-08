#include <iostream>
#include "Number.h"
#include "BinaryOperation.h"

bool check_equals(Expression const* expression1, Expression const* expression2) {
    return *(long long*)expression1 == *(long long*)expression2;
}

int main() {
    Expression* sube = new BinaryOperation(new Number(-4.5), '*', new Number(-2));
    Expression* expr = new BinaryOperation(new Number(-3), '+', sube);
    std::cout << expr->evaluate() << std::endl;
    std::cout << check_equals(sube, expr);
    delete expr;
    return 0;
}
