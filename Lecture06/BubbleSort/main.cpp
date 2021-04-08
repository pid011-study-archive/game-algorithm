#include <iostream>
#include <random>
#include "BubbleSort.h"

int main()
{
    BubbleSort sort(100);

    std::random_device rand;
    std::mt19937 randomGen(rand());
    std::uniform_int_distribution<int> dist(1, 99);

    int data[100];
    for (size_t i = 0; i < 100; i++)
    {
        data[i] = dist(randomGen);
    }

    sort.initData(data);
    sort.draw();
    sort.sorting();
    std::cout << std::endl;
    sort.draw();
}