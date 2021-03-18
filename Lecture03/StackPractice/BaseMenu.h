#pragma once
#include "MenuStack.h"

class MenuStack;

class BaseMenu
{
public:
    /// <summary>
    /// �޴��� ������
    /// </summary>
    virtual void ShowMenu() = 0;

    /// <summary>
    /// ������ �޴��� ������
    /// </summary>
    /// <param name="idx">������ �޴� ��ȣ (0���� ����)</param>
    /// <param name="stack">�޴� ����</param>
    virtual void Process(int idx, MenuStack& stack) = 0;
};
