#include <iostream>
#include "HeapSort.h"
#include "QuickSort.h"
#include "MergeSort.h"

void print(int arr[], int n) {
    std::cout << "Текущий массив : ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

void binsearch(int arr[], int x, int n) {
    int l = 0, r = n - 1;

    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m;
    }

    if (arr[l] != x) {
        std::cout << "Числа " << x << " в массиве нет\n";
        return;
    }
    std::cout << "Первое вхождение числа " << x << " в массив = " << l + 1 << '\n';
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    //HeapSort::heapSort(arr, n);
    //print(arr, n);

    QuickSort::quickSort(arr, 0, n - 1);
    print(arr, n);

    //MergeSort::mergeSort(arr, 0, n - 1);
    //print(arr, n);

    int x;
    std::cin >> x;
    binsearch(arr, x, n);

    return 0;
}
