#include <iostream>
#include <vector>

int getmid(int x, int y, int z) {
    if (x >= y && x <= z)
        return x;
    if (y >= x && y <= z)
        return y;
    return z;
}

int main() {
    int n;
    //std::cin >> n;
    std::vector<int> a;
    std::vector<double> b;

    /*for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        a.push_back(x);
    }*/
    a = { 1, 5, 1, 4, 5, 6, 2, 1, 3, 4, 4, 4, 5, 7 };
    n = a.size();

    int i = 0;

    while (i < n) {
        if (i + 2 < n) {
            b.push_back(getmid(a[i], a[i + 1], a[i + 2]));
            i += 3;
            continue;
        }

        if (i == n - 1) {
            b.push_back(a[i]);
            i++;
            continue;
        }

        double sum = (a[i] + a[i + 1]);
        b.push_back(sum / 2);
        i += 2;
    }

    for (auto u : b) {
        std::cout << u << ' ';
    }

    return 0;
}
