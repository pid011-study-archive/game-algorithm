#include "MenuStack.h"

MenuStack::MenuStack() : _head(nullptr), _count(0)
{
}

MenuStack::~MenuStack()
{
    while (_count != 0) ExitMenu();
}

void MenuStack::Open(BaseMenu* menu)
{
    Node* newNode = new Node { _head, menu };
    _head = newNode;

    _count++;
}

bool MenuStack::ExitMenu()
{
    if (_count == 0) return false;

    Node* delNode = _head;
    _head = _head->Next;

    delete delNode->Item;
    delete delNode;

    _count--;
    return true;
}

BaseMenu* MenuStack::GetCurrentMenu()
{
    if (_count == 0) return nullptr;

    return _head->Item;
}
