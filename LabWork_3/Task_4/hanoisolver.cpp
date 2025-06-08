#include "hanoisolver.h"

HanoiSolver::HanoiSolver() {}

int HanoiSolver::interm(int a, int b) {
    if (a == 1) {
        if (b == 2)
            return 3;
        else
            return 2;
    }

    if (a == 2) {
        if (b == 1)
            return 3;
        else
            return 1;
    }

    if (b == 2)
        return 1;
    else
        return 2;
}

QVector<std::pair<int, int>> HanoiSolver::solve(int n, int f, int s) {
    if (n == 1) {
        return {std::make_pair(f, s)};
    }

    int iPillar = HanoiSolver::interm(f, s);
    QVector<std::pair<int, int>> Vsolve = solve(n - 1, f, iPillar);
    Vsolve.push_back(std::make_pair(f, s));
    QVector<std::pair<int, int>> Isolve = solve(n - 1, iPillar, s);

    for (auto u : Isolve) {
        Vsolve.push_back(u);
    }

    return Vsolve;
}
