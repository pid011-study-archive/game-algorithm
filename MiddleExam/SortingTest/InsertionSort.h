#pragma once
#include <utility>
#include "CSort.h"

class InsertionSort : public CSort
{
public:
    InsertionSort(int max) : CSort(max) { }
    virtual void sorting() override;
};

void InsertionSort::sorting()
{
    int* data = getData();
    int len = getSize();

    for (int i = 1; i < len; i++)
    {
        if (data[i - 1] < data[i]) continue; // 만약 이전 인덱스의 데이터가 현재 인덱스의 데이터보다 크면

        int td = data[i]; // 현재 인덱스 데이터 저장
        int ti = i;       // 현재 인덱스 저장

        // 더 작은 수가 나올 때까지 1씩 감소하면서 시프트
        for (; ti > 0 && data[ti - 1] > td; ti--)
        {
            data[ti] = data[ti - 1];
        }
        data[ti] = td; // 찾은 위치로 값 저장
    }
}

/*
4 11 19 8 19 19 2 2 19 5 16 17 3 4 9 3 18 11 15 2
2 2 2 3 3 4 4 5 8 9 11 11 15 16 17 18 19 19 19 19
*/
