#pragma once
#include "Vector2Queue.h"

class Character
{
public:
    Character(const Vector2& initPosition) : _position(initPosition) { }
    const Vector2& CurrentPosition() { return _position; }

    void Move(const Vector2& nextPosition);

private:
    Vector2 _position;
};
