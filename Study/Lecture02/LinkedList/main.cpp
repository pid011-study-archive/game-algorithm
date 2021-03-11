#include <iostream>
#include "IntLinkedList.h"

int main()
{
    using namespace std;

    CIntLinkedList list;

    cout << "is empty: " << (list.IsEmpty() ? "true" : "false") << endl;

    for (int i = 0; i < 10; i++)
    {
        list.InsertData(i, i + 1);
    }
    list.Draw();

    cout << endl;

    cout << "item of index 6: " << list.RetrieveData(6) << endl;

    cout << endl;

    cout << "Remove item of index 0." << endl;
    list.RemoveData(0);
    list.Draw();

    cout << endl;

    cout << "Remove item of index 4." << endl;
    list.RemoveData(4);
    list.Draw();

    cout << endl;

    cout << "Remove item of index 7." << endl;
    list.RemoveData(7);
    list.Draw();

    cout << endl;

    cout << "Insert item of index 0." << endl;
    list.InsertData(0, 100);
    list.Draw();

    cout << endl;

    cout << "Insert item of index 1." << endl;
    list.InsertData(1, 200);
    list.Draw();

    cout << endl;

    cout << "Remove item of index -1." << endl;
    list.RemoveData(-1);
    list.Draw();
}

/*
is empty: true
1 2 3 4 5 6 7 8 9 10

item of index 6: 7

Remove item of index 0.
2 3 4 5 6 7 8 9 10

Remove item of index 4.
2 3 4 5 7 8 9 10

Remove item of index 7.
2 3 4 5 7 8 9

Insert item of index 0.
100 2 3 4 5 7 8 9

Insert item of index 1.
100 200 2 3 4 5 7 8 9

Remove item of index -1.
Remove failed.
100 200 2 3 4 5 7 8 9
*/