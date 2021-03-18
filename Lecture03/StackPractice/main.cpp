#include <iostream>
#include "MainMenu.h"
#include "SoundMenu.h"
#include "MenuStack.h"

int main()
{
    MenuStack menus;
    menus.Open(new MainMenu);

    BaseMenu* currentMenu = nullptr;

    while ((currentMenu = menus.GetCurrentMenu()) != nullptr)
    {
        currentMenu->ShowMenu();

        std::cout << "========================" << std::endl
                  << "Choice: ";

        int choice;
        std::cin >> choice;
        currentMenu->Process(choice, menus);

        std::cout << std::endl;
    }
}