#include "HashTableManager.h"

HashTableManager::HashTableManager() :
    hTsize(100)
{
    shash = new SumHash;
    xhash = new XorHash;
    currenthash = shash;
    table = new HashTable(hTsize, currenthash);
}

HashTableManager::~HashTableManager()
{
    delete table;
    delete xhash;
    delete shash;
}

void HashTableManager::changeHash()
{
    if (currenthash == shash)
        currenthash = xhash;
    else
        currenthash = shash;
    table->rebuildTable(hTsize, currenthash);
}

void HashTableManager::menu()
{
    cout << "0 - exit" << endl
         << "1 - add" << endl
         << "2 - search" << endl
         << "3 - remove" << endl
         << "4 - show statistics" << endl
         << "5 - change hash" << endl;
}

void HashTableManager::showStatistics()
{
    cout << "Quantity of elements - " << table->getElemQuantity() << endl
         << "Quantity of collisions - " << table->getCollisions() << endl
         << "Max collision length - " << table->getMaxCollLength() << endl
         << "Loadfacot - " << table->getLoadFactor() << endl;
}

void HashTableManager::dialog()
{
    cout << "Hash have been chosen automatically: SumHash." << endl;
    char keyPressed = 'x';
    while (keyPressed != '0')
    {
        menu();
        cin >> keyPressed;

        string str;
        switch (keyPressed)
        {
        case '1':
        {
            cout << "Enter the word you want to add: ";
            cin >> str;
            cout << endl;
            table->add(str, 1);
            break;
        }
        case '2':
            cout << "Enter the value you want to search: ";
            cin >> str;
            cout << endl;
            if (table->isExist(str))
            {
                cout << "Word is exist." << endl;
            }
            else
                cout << "No such word." << endl;
            break;
        case '3':
            cout << "Enter the word you want to remove: ";
            cin >> str;
            cout << endl;
            try
            {
                table->remove(str);
            }
            catch (string exc)
            {
                cout << exc << endl;
            }
            break;
        case '4':
            cout << endl;
            showStatistics();
            cout << endl;
            break;
        case '5':
            changeHash();
            cout << "Hash Function has successfully changed." << endl;
            break;
        }
    }
}
