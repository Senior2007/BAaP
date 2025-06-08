#ifndef TASK_3_BINARYOPERATION_H
#define TASK_3_BINARYOPERATION_H

#include "Expression.h"

class BinaryOperation : public Expression {
private:
    Expression* left;
    Expression* right;
    char operation;
public:
    BinaryOperation(Expression* left, char operation, Expression* right);
    ~BinaryOperation() override;
    double evaluate() const override;
};


#endif //TASK_3_BINARYOPERATION_H
