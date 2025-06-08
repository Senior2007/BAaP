#include <iostream>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

void interpolationSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int l = 0, r = i - 1;

        while (l <= r) {
            int pos = l + ((key - arr[l]) * (r - l)) / (arr[r] - arr[l] + 1);

            if (pos < l) pos = l;
            if (pos > r) pos = r;

            if (arr[pos] < key)
                l = pos + 1;
            else
                r = pos - 1;
        }

        for (int j = i - 1; j >= l; j--)
            arr[j + 1] = arr[j];
        arr[l] = key;

        std::cout << "Step " << i << ": ";
        print(arr, n);
    }
}

int binsearch(int arr[], int x, int n) {
    int l = 0, r = n - 1;

    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m;
    }

    if (arr[l] != x) {
        return -1;
    }
    return l + 1;
}


int binpow(int x, int power, int mod) {
    if (power == 1)
        return x % mod;

    if (power % 2)
        return (x * binpow(x, power - 1, mod)) % mod;

    int answer = binpow(x, power / 2, mod);
    return (answer * answer) % mod;
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    interpolationSort(arr, n);

    int x;
    std::cin >> x;
    std::cout << binpow(binsearch(arr, x, n), n, x);

    return 0;
}
