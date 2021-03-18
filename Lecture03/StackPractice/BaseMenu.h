#pragma once
#include "MenuStack.h"

class MenuStack;

class BaseMenu
{
public:
    /// <summary>
    /// 메뉴를 보여줌
    /// </summary>
    virtual void ShowMenu() = 0;

    /// <summary>
    /// 선택한 메뉴를 실행함
    /// </summary>
    /// <param name="idx">선택할 메뉴 번호 (0부터 시작)</param>
    /// <param name="stack">메뉴 스택</param>
    virtual void Process(int idx, MenuStack& stack) = 0;
};
