#pragma once
#include <iostream>

class CSort
{
    int* m_iData;
    int m_dataSize;

public:
    CSort(int Max = 100) : m_dataSize(Max)
    {
        m_iData = new int[Max];
    }

    virtual ~CSort()
    {
        if (m_iData)
        {
            delete[] m_iData;
        }
    }

    virtual void initData(int* data)
    {
        for (int i = 0; i < m_dataSize; i++)
        {
            m_iData[i] = data[i];
        }
    }

    virtual void sorting() = 0;
    virtual void draw() const
    {
        for (int i = 0; i < m_dataSize; i++)
        {
            std::cout << m_iData[i] << ' ';
        }
        std::cout << std::endl;
    }
    int getSize() const { return m_dataSize; }
    int* getData() const { return m_iData; }
};
