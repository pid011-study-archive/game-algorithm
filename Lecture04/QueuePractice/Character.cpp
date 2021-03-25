#include "Character.h"
#include <iostream>

void Character::Move(const Vector2& nextPosition)
{
    const Vector2 &start = CurrentPosition(), &end = nextPosition;

    // y = ax + b
    float a = (end.Y - start.Y) / (end.X - start.X);
    float b = start.Y - (a * start.X);

    std::cout << "start: " << start.ToString() << std::endl;

    Vector2 r;
    if (start.X < end.X)
    {
        for (float x = start.X + 1; x < end.X; x++)
        {
            float y = a * x + b;
            r = Vector2 { x, y };
            std::cout << "move: " << r.ToString() << std::endl;
        }
    }
    else
    {
        for (float x = start.X - 1; x > end.X; x--)
        {
            float y = a * x + b;
            r = Vector2 { x, y };
            std::cout << "move: " << r.ToString() << std::endl;
        }
    }

    _position = nextPosition;
    std::cout << "end: " << start.ToString() << std::endl;
}
