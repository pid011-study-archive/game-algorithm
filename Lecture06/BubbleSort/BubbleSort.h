#pragma once
#include <utility>
#include "CSort.h"

class BubbleSort : public CSort
{
public:
    BubbleSort(int max) : CSort(max) { }
    virtual void sorting() override
    {
        int* data = getData();
        size_t len = getSize();

        bool sorted = false;
        for (size_t pass = 1; pass < len && !sorted; pass++)
        {
            sorted = true;
            for (size_t current = 0; current < len - pass; current++)
            {
                if (data[current] > data[current + 1])
                {
                    std::swap(data[current], data[current + 1]);
                    sorted = false;
                }
            }
        }
    }
};