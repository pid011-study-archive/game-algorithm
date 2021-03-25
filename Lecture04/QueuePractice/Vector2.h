#pragma once
#include <string>

struct Vector2
{
    float X = 0, Y = 0;

    std::string ToString() const
    {
        std::string str = "(" + std::to_string(X) + ", " + std::to_string(Y) + ")";
        return str;
    }
};