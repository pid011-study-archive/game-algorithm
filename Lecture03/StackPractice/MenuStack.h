#pragma once
#include "BaseMenu.h"

class BaseMenu;

struct Node
{
    Node* Next;
    BaseMenu* Item;
};

class MenuStack
{
public:
    MenuStack();
    ~MenuStack();
    void Open(BaseMenu* menu);
    bool ExitMenu();
    BaseMenu* GetCurrentMenu();
    size_t Count() { return _count; }

private:
    Node* _head;
    size_t _count;
};
