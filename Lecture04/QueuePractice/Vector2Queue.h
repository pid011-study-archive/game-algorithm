#pragma once
#include "Vector2.h"
#include <stdexcept>

struct Vector2Node
{
    Vector2 Data;
    Vector2Node* Next;
};

class Vector2Queue
{
public:
    Vector2Queue() { }
    ~Vector2Queue()
    {
        while (Length() != 0) Dequeue();
    }

    void Enqueue(const Vector2& item)
    {
        Vector2Node* temp = new Vector2Node { Vector2(item), nullptr };

        if (!_tail)
        {
            _front = temp;
            _tail = temp;
        }
        else
        {
            _tail->Next = temp;
            _tail = temp;
        }

        _length++;
    }

    Vector2 Dequeue()
    {
        if (Length() == 0) throw std::length_error("Queue is empty.");

        Vector2 retval = _front->Data;
        Vector2Node* temp = _front;
        _front = _front->Next;

        if (!_front) _tail = nullptr;

        delete temp;
        _length--;

        return retval;
    }

    std::size_t Length() { return _length; }

private:
    Vector2Node* _front { nullptr };
    Vector2Node* _tail { nullptr };
    std::size_t _length { 0 };
};
