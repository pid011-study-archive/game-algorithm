#include <iostream>
#include "Character.h"
#include "Vector2Queue.h"

Vector2 InputPosition()
{
    using namespace std;

    cout << "Input: ";
    float x, y;
    cin >> x >> y;

    return Vector2 { x, y };
}

int main()
{
    Character character(Vector2 { 0, 0 });

    Vector2Queue inputQueue;
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << i + 1 << ". ";
        Vector2 pos = InputPosition();
        inputQueue.Enqueue(pos);
    }

    while (inputQueue.Length() != 0)
    {
        Vector2 pos = inputQueue.Dequeue();

        std::cout << "====================" << std::endl;
        character.Move(pos);
        std::cout << "====================" << std::endl;
    }
}

/*
1. Input: 1 2
2. Input: -5 -3
3. Input: 2 10
====================
start: (0.000000, 0.000000)
end: (1.000000, 2.000000)
====================
====================
start: (1.000000, 2.000000)
move: (0.000000, 1.166667)
move: (-1.000000, 0.333333)
move: (-2.000000, -0.500000)
move: (-3.000000, -1.333333)
move: (-4.000000, -2.166667)
end: (-5.000000, -3.000000)
====================
====================
start: (-5.000000, -3.000000)
move: (-4.000000, -1.142857)
move: (-3.000000, 0.714286)
move: (-2.000000, 2.571429)
move: (-1.000000, 4.428571)
move: (0.000000, 6.285714)
move: (1.000000, 8.142857)
end: (2.000000, 10.000000)
====================
*/