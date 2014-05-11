#pragma once

#include "List.h"
#include "HashFunction.h"


class HashTable
{
public:
    HashTable(unsigned int size, HashFunction *hashFunct);
    ~HashTable();
    void createTable();
    void add (string str, unsigned int quantity);
    void remove (string str) throw (string);
    bool isExist (string str);
    void rebuildTable(unsigned int newSize, HashFunction *hashFunct);
    void checkOverFlow();
    unsigned int HTsize;
    unsigned int Collisions;
    unsigned int MaxCollLength;
    unsigned int ElemQuantity;
    double LoadFactor;
    HashFunction *hash;
    List **table;
};

