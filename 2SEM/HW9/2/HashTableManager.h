#pragma once

#include "HashTable.h"

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
    unsigned int HTsize;
    HashFunction *shash;
    HashFunction *xhash;
    HashFunction *currenthash;
};

