#include "task_3.h"
#include <cmath>

Task_3::Task_3() {}

int Task_3::GetLen(int n) {
    if (n == 0) {
        return 0;
    }

    return 1 + GetLen(n / 10);
}

int Task_3::Calc(int x, int len) {
    if (len == 1) {
        return x;
    }

    int st = static_cast<int>(pow(10, len - 1));
    int curD = x / st;
    int newX = Calc(x % st, len - 1);

    return newX * 10 + curD;
}

int Task_3::Task3(int x) {
    return Calc(x, GetLen(x));
}
