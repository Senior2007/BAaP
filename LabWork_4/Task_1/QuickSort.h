#ifndef TASK_1_QUICKSORT_H
#define TASK_1_QUICKSORT_H
#include <iostream>

class QuickSort {
public:
    static int partition(int arr[], int low, int high);
    static void quickSort(int arr[], int low, int high);
};


#endif //TASK_1_QUICKSORT_H
