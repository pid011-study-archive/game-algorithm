#pragma once
#include <iostream>

struct Node
{
    Node* next;
    int data;
};

class CIntLinkedList
{
public:
    CIntLinkedList();
    ~CIntLinkedList();
    void InsertData(int pos, int item);
    void RemoveData(int pos);
    int RetrieveData(int pos);
    void Draw();
    bool IsEmpty() { return m_count == 0; }

private:
    int m_count;
    Node* m_head;
};

CIntLinkedList::CIntLinkedList() : m_count(0), m_head(nullptr)
{
}

CIntLinkedList::~CIntLinkedList()
{
    while (m_head != nullptr)
    {
        Node* nextNode = m_head->next;
        delete m_head;
        m_head = nextNode;
        --m_count;
    }
}

void CIntLinkedList::InsertData(int pos, int item)
{
    if (pos < 0 || pos > m_count)
    {
        std::cout << "Insert failed." << std::endl;
        return;
    }

    Node* insertNode = new Node { nullptr, item };

    if (pos == 0)
    {
        insertNode->next = m_head;
        m_head = insertNode;
    }
    else
    {
        Node* prevNode = m_head;

        for (int i = 0; i < pos - 1; i++)
        {
            prevNode = prevNode->next;
        }
        insertNode->next = prevNode->next;
        prevNode->next = insertNode;
    }

    ++m_count;
}

void CIntLinkedList::RemoveData(int pos)
{
    if (pos < 0 || pos >= m_count)
    {
        std::cout << "Remove failed." << std::endl;
        return;
    }

    if (pos == 0)
    {
        Node* nextNode = m_head->next;
        delete m_head;
        m_head = nextNode;
    }
    else
    {
        Node* prevNode = m_head;

        for (int i = 0; i < pos - 1; i++)
        {
            prevNode = prevNode->next;
        }
        Node* targetNode = prevNode->next;
        prevNode->next = targetNode->next;
        delete targetNode;
    }

    --m_count;
}

int CIntLinkedList::RetrieveData(int pos)
{
    if (pos < 0 || pos >= m_count)
    {
        std::cout << "Retrieve failed." << std::endl;
        return 0;
    }

    Node* retrieveNode = m_head;
    for (int i = 0; i < pos; i++)
    {
        retrieveNode = retrieveNode->next;
    }

    return retrieveNode->data;
}

void CIntLinkedList::Draw()
{
    using namespace std;

    Node* drawNode = m_head;

    for (int i = 0; i < m_count; i++)
    {
        cout << drawNode->data << ' ';
        drawNode = drawNode->next;
    }

    //while (drawNode != nullptr)
    //{
    //    cout << drawNode->data << ' ';
    //    drawNode = drawNode->next;
    //}

    cout << endl;
}