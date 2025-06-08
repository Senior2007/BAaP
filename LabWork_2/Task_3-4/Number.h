#ifndef TASK_3_NUMBER_H
#define TASK_3_NUMBER_H

#include "Expression.h"

class Number : public Expression {
private:
    double value;
public:
    Number(double value);
    double evaluate() const override;
};


#endif //TASK_3_NUMBER_H
