#ifndef TASK_3_EXPRESSION_H
#define TASK_3_EXPRESSION_H

class Expression {
public:
    virtual ~Expression() = default;
    virtual double evaluate() const = 0;
};


#endif //TASK_3_EXPRESSION_H
