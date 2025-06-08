#ifndef TASK_1_H
#define TASK_1_H
#include <QString>

class Task_1
{
public:
    Task_1();
    static QString Task1Int(int x);
    static QString Task1Frac(double x, int depth);
    static QString Task1(double x);
};

#endif // TASK_1_H
