#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std::chrono;
using std::vector;

void SortingTest(int length);
void SortingTestWithSortedArray(int length);
void SortingTestWithReversedArray(int length);

void CheckBubbleSort(const vector<int>& input, int len);
void CheckInsertionSort(const vector<int>& input, int len);
void CheckSelectionSort(const vector<int>& input, int len);
void CheckMergeSort(const vector<int>& input, int len);
void CheckQuickSort(const vector<int>& input, int len);

void PrintSomeElements(int* sources, int length, int printCount);

int main()
{
    //SortingTest(3000);
    //SortingTest(5000);
    //SortingTest(10000);

    //SortingTestWithSortedArray(3000);
    //SortingTestWithSortedArray(5000);
    //SortingTestWithSortedArray(10000);

    SortingTestWithReversedArray(3000);
    SortingTestWithReversedArray(5000);
    SortingTestWithReversedArray(10000);
}

void SortingTest(int length) 
{
    std::cout << "-----------------------------------------------------------------" << std::endl;

    std::cout << "[test case : length = " << length << "]" << std::endl;

    std::random_device rand;
    std::mt19937 randomGen(rand());
    std::uniform_int_distribution<int> dist(1, length);

    std::vector<int> sources(length);

    for (size_t i = 0; i < length; i++) sources[i] = dist(randomGen);

    std::cout << "-unsorted elemets-" << std::endl;
    PrintSomeElements(&sources[0], sources.size(), 20);
    std::cout << std::endl;

    CheckSelectionSort(sources, length);
    CheckBubbleSort(sources, length);
    CheckInsertionSort(sources, length);
    CheckMergeSort(sources, length);
    CheckQuickSort(sources, length);

    std::cout << "-----------------------------------------------------------------" << std::endl;
}

void SortingTestWithSortedArray(int length)
{
    std::cout << "-----------------------------------------------------------------" << std::endl;

    std::cout << "[test case : length = " << length << "]" << std::endl;

    std::vector<int> sources(length);
    for (size_t i = 0; i < length; i++) sources[i] = i;

    std::cout << "-unsorted elemets-" << std::endl;
    PrintSomeElements(&sources[0], sources.size(), 20);
    std::cout << std::endl;

    CheckSelectionSort(sources, length);
    CheckBubbleSort(sources, length);
    CheckInsertionSort(sources, length);
    CheckMergeSort(sources, length);
    CheckQuickSort(sources, length);

    std::cout << "-----------------------------------------------------------------" << std::endl;
}

void SortingTestWithReversedArray(int length)
{
    std::cout << "-----------------------------------------------------------------" << std::endl;

    std::cout << "[test case : length = " << length << "]" << std::endl;

    std::vector<int> sources(length);
    for (size_t i = 0; i < length; i++) sources[i] = length - i - 1;

    std::cout << "-unsorted elemets-" << std::endl;
    PrintSomeElements(&sources[0], sources.size(), 20);
    std::cout << std::endl;

    CheckSelectionSort(sources, length);
    CheckBubbleSort(sources, length);
    CheckInsertionSort(sources, length);
    CheckMergeSort(sources, length);
    CheckQuickSort(sources, length);

    std::cout << "-----------------------------------------------------------------" << std::endl;
}

void CheckBubbleSort(const vector<int>& input, int len)
{
    // deep copy
    vector<int> sources = input;

    BubbleSort sort(len);
    sort.initData(&sources[0]);

    auto start = system_clock::now();
    sort.sorting();
    auto end = system_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    std::cout << "bubble sort: " << duration.count() << "μs" << std::endl;
    PrintSomeElements(sort.getData(), sort.getSize(), 20);
}

void CheckInsertionSort(const vector<int>& input, int len)
{
    vector<int> sources = input;

    InsertionSort sort(len);
    sort.initData(&sources[0]);

    auto start = system_clock::now();
    sort.sorting();
    auto end = system_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    std::cout << "insertion sort: " << duration.count() << "μs" << std::endl;
    PrintSomeElements(sort.getData(), sort.getSize(), 20);
}

void CheckSelectionSort(const vector<int>& input, int len)
{
    vector<int> sources = input;

    SelectionSort sort(len);
    sort.initData(&sources[0]);

    auto start = system_clock::now();
    sort.sorting();
    auto end = system_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    std::cout << "selection sort: " << duration.count() << "μs" << std::endl;
    PrintSomeElements(sort.getData(), sort.getSize(), 20);
}

void CheckMergeSort(const vector<int>& input, int len)
{
    vector<int> sources = input;

    MergeSort sort(len);
    sort.initData(&sources[0]);

    auto start = system_clock::now();
    sort.sorting();
    auto end = system_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    std::cout << "merge sort: " << duration.count() << "μs" << std::endl;
    PrintSomeElements(sort.getData(), sort.getSize(), 20);
}

void CheckQuickSort(const vector<int>& input, int len)
{
    vector<int> sources = input;

    QuickSort sort(len);
    sort.initData(&sources[0]);

    auto start = system_clock::now();
    sort.sorting();
    auto end = system_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    std::cout << "quick sort: " << duration.count() << "μs" << std::endl;
    PrintSomeElements(sort.getData(), sort.getSize(), 20);
}

void PrintSomeElements(int* sources, int length, int printCount)
{
    int range = length < printCount ? length : printCount;
    for (int i = 0; i < range; i++) std::cout << sources[i] << " ";
    if (length > range) std::cout << "...";

    std::cout << std::endl;
}

