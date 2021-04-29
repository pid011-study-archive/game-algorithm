#pragma once
#include <utility>
#include "CSort.h"

class SelectionSort : public CSort
{
public:
    SelectionSort(int max) : CSort(max) { }

    virtual void sorting() override;
};

void SelectionSort::sorting()
{
    int* data = getData();

    for (size_t last = getSize() - 1; last >= 1; last--)
    {
        size_t largest = 0;
        for (size_t current = 1; current <= last; current++)
        {
            if (data[current] > data[largest])
            {
                largest = current;
            }
        }
        std::swap(data[largest], data[last]);
    }
}