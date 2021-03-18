#pragma once
#include "BaseMenu.h"

class MainMenu : public BaseMenu
{
public:
    void ShowMenu() override;
    void Process(int idx, MenuStack& stack) override;
};
