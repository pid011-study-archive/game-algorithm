#pragma once
#include <utility>
#include <vector>
#include "CSort.h"

class MergeSort : public CSort
{
public:
    MergeSort(int max) : CSort(max) { }
    virtual void sorting() override;
};

void devide(int* arr, int first, int last);
void merge(int* arr, int first, int middle, int last);

void MergeSort::sorting()
{
    int* data = getData();
    int len = getSize();

    devide(data, 0, len - 1);
}

void devide(int* arr, int first, int last)
{
    if (first < last)
    {
        int middle = (first + last) / 2;
        devide(arr, first, middle);
        devide(arr, middle + 1, last);
        merge(arr, first, middle, last);
    }
}

void merge(int* arr, int first, int middle, int last)
{
    std::vector<int> result;

    int f1 = first, f2 = middle + 1;

    int i = f1;
    while (f1 <= middle && f2 <= last)
    {
        if (arr[f1] <= arr[f2])
        {
            result.push_back(arr[f1++]);
        }
        else
        {
            result.push_back(arr[f2++]);
        }
    }

    for (; f1 <= middle; f1++) result.push_back(arr[f1]);
    for (; f2 <= last; f2++) result.push_back(arr[f2]);

    for (int i = first; i <= last; i++)
    {
        arr[i] = result[i - first];
    }
}
