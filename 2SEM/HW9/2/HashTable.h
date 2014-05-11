#pragma once

#include "List.h"
#include "HashFunction.h"

/// Clases for hashTable

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
    unsigned int getHTsize();
    unsigned int getCollisions();
    unsigned int getMaxCollLength();
    unsigned int getElemQuantity();
    double getLoadFactor();
    HashFunction* getHashFunction();  
    List **getTable();
    
    
private:
    unsigned int hTsize;
    unsigned int collisions;
    unsigned int maxCollLength;
    unsigned int elemQuantity;
    double loadFactor;
    HashFunction *hash;
    List **table;
};

