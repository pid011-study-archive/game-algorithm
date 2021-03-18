#pragma once
#include "BaseMenu.h"

class SoundMenu : public BaseMenu
{
public:
    void ShowMenu() override;
    void Process(int idx, MenuStack& stack) override;
};
