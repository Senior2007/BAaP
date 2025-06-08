#include "task_2.h"

Task_2::Task_2() {}

std::map<std::pair<int, int>, int> mp;

int Task_2::A(int m, int n) {
    std::pair<int, int> par = std::make_pair(m, n);

    if (mp[par] != 0) {
        return mp[par];
    }

    if (m == 0) {
        mp[par] = n + 1;
        return n + 1;
    }

    if (m > 0 && n == 0) {
        mp[par] = A(m - 1, 1);
        return mp[par];
    }

    mp[par] = A(m - 1, A(m, n - 1));
    return mp[par];
}
