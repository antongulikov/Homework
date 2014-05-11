#pragma once

#include "HashTable.h"

/** HashTableManager class.
    It shows dialog and help user to work with HashTable:
    Add word,
    Search word,
    Remove word,
    Show Statictics.
    Change Hash */

class HashTableManager
{
public:
    HashTableManager();
    ~HashTableManager();
    void dialog();
private:
    void showStatistics();
    void changeHash();
    void menu();
    HashTable *table;
    unsigned int hTsize;
    HashFunction *shash;
    HashFunction *xhash;
    HashFunction *currenthash;
};

