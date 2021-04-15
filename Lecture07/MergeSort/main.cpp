#include <iostream>
#include <random>
#include "MergeSort.h"

int main()
{
    const int len = 20;
    MergeSort sort(len);

    std::random_device rand;
    std::mt19937 randomGen(rand());
    std::uniform_int_distribution<int> dist(1, len - 1);

    int data[len];
    for (size_t i = 0; i < len; i++)
    {
        data[i] = dist(randomGen);
    }

    sort.initData(data);
    sort.draw();
    sort.sorting();
    sort.draw();
}
