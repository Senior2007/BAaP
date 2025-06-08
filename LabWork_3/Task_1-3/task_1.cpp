#include "task_1.h"

Task_1::Task_1() {}

QString Task_1::Task1Int(int x) {
    if (x == 0) {
        return "";
    }

    char c = '0';
    if (x % 2) {
        c = '1';
    }
    return Task1Int(x / 2) + c;
}

QString Task_1::Task1Frac(double x, int depth) {
    if (depth == 15 || x == 0) {
        return "";
    }

    x *= 2;
    char c = '0';
    if (x >= 1) {
        c = '1';
    }

    QString res = c + Task1Frac(x - 1 * (x >= 1), depth + 1);
    return res;
}

QString Task_1::Task1(double x) {
    bool pr = 0;
    if (x != trunc(x) && x < 0) {
        x = -x;
        pr = 1;
    }

    int intX = static_cast<int>(x);
    double ostX = x - intX;
    QString result = Task1Int(intX);
    if (result == "") {
        result = '0';
    }

    if (intX < 0) {
        while(result.size() != 32) {
            result = '0' + result;
        }

        for (int i = 0; i < 32; i++) {
            if (result[i] == '0') {
                result[i] = '1';
            } else {
                result[i] = '0';
            }
        }

        for (int i = 31; i >= 0; i--) {
            if (result[i] == '1') {
                result[i] = '0';
            } else {
                result[i] = '1';
                break;
            }
        }
    }

    if (ostX != 0) {
        result += '.';
        result += Task1Frac(ostX, 0);
    }

    if (pr) {
        result = '-' + result;
    }

    return result;
}
