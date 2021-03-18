#include "MainMenu.h"
#include "SoundMenu.h"
#include <iostream>

void MainMenu::ShowMenu()
{
    using namespace std;

    cout << "1. Start Game" << endl
         << "2. Save Game" << endl
         << "3. Sound Settings" << endl
         << "4. Exit" << endl;
}

void MainMenu::Process(int idx, MenuStack& stack)
{
    using namespace std;

    switch (idx)
    {
    case 1:
        cout << "Starting Game..." << endl;
        break;

    case 2:
        cout << "Saving Game..." << endl;
        break;

    case 3:
        cout << "Open Sound Settings." << endl;
        stack.Open(new SoundMenu);
        break;
    case 4:
        cout << "Exit the Game." << endl;
        stack.ExitMenu();
        break;
    default:
        cout << "Wrong choice." << endl;
        break;
    }
}
