#include "SoundMenu.h"
#include <iostream>

void SoundMenu::ShowMenu()
{
    using namespace std;

    cout << "1. Sound On" << endl
         << "2. Sound Off" << endl
         << "3. Back to main" << endl;
}

void SoundMenu::Process(int idx, MenuStack& stack)
{
    using namespace std;

    switch (idx)
    {
    case 1:
        cout << "Sound On." << endl;
        break;

    case 2:
        cout << "Sound Off." << endl;
        break;

    case 3:
        cout << "Go to main menu." << endl;
        stack.ExitMenu();
        break;

    default:
        cout << "Wrong choice." << endl;
        break;
    }
}
