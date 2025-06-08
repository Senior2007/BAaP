#ifndef HANOISOLVER_H
#define HANOISOLVER_H

#include <QVector>

class HanoiSolver
{
public:
    HanoiSolver();
    static int interm(int x, int y);
    static QVector<std::pair<int, int>> solve(int n, int f, int s);
};

#endif // HANOISOLVER_H
