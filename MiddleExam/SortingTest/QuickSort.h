#pragma once
#include <utility>
#include <vector>
#include "CSort.h"

class QuickSort : public CSort
{
public:
    QuickSort(int max) : CSort(max) { }
    virtual void sorting() override;
};

void quicksort(int arr[], int low, int hight);
int partition(int arr[], int low, int hight);

void QuickSort::sorting()
{
    int* data = getData();
    int size = getSize();

    quicksort(data, 0, size - 1);
}

void quicksort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

int partition(int arr[], int left, int right)
{
    int item = arr[right];
    int pivot = left;

    for (int i = left; i <= right; i++)
    {
        if (arr[i] < item)
        {
            std::swap(arr[i], arr[pivot]);
            pivot++;
        }
    }

    std::swap(arr[right], arr[pivot]);
    return pivot;
}
