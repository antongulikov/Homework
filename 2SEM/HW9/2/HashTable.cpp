#include "HashTable.h"

HashTable::HashTable(unsigned int size, HashFunction *hashFunct) :
    hTsize(size),

    collisions(0),
    maxCollLength(0),
    elemQuantity(0),
    LoadFactor(0),
    hash(hashFunct)
{
    createTable();
}

void HashTable::createTable()
{
    table = new List *[hTsize];
    for (unsigned int i = 0; i < hTsize; i++)
    {
        table[i] = NULL;
    }
}

void HashTable::add(string str, unsigned int quantity)
{
    unsigned long long int index = hash->hash(str) % hTsize;
    if (table[index] == NULL)
    {
        table[index] = new List();
        table[index]->add(str, quantity);
        elemQuantity++;
        LoadFactor += 1.0 / double(hTsize);
        return;
    }
    unsigned int listSize = table[index]->getSize();
    table[index]->add(str, quantity);
    if (table[index]->getSize() > listSize)
    {
        collisions++;
        elemQuantity++;
        if (maxCollLength < table[index]->getSize() - 1)
            maxCollLength = table[index]->getSize() - 1;
    }
}


void HashTable::remove(string str) throw (string)
{
    unsigned long long int index = hash->hash(str) % hTsize;
    if (table[index] != NULL)
    {
        try
        {
            table[index]->remove(str);
        }
        catch (string exc)
        {
            cout << exc << endl;

        }
    }
    else
        throw string("No such word");
}

bool HashTable::isExist(string str)
{
    unsigned long long int index = hash->hash(str) % hTsize;
    if (table[index] != NULL && !table[index]->isEmpty())
    {
        ListElement *temp = table[index]->getHead();
        while(temp->getNext() != NULL)
        {
            if (temp->getStr() == str)
            {
                return true;
            }
            else
            {
                temp = temp->getNext();
            }
        }
        return temp->getStr() == str;
    }
    else
        return false;
}

void HashTable::rebuildTable(unsigned int newSize, HashFunction *hashFunct)
{
    List **oldTable = table;
    unsigned int oldSize = hTsize;
    hTsize = newSize;
    createTable();
    collisions = 0;
    maxCollLength = 0;
    LoadFactor = 0;
    elemQuantity = 0;
    hash = hashFunct;
    for (unsigned int i = 0; i < oldSize; i++)
    {
        if (oldTable[i] != NULL && !oldTable[i]->isEmpty())
        {
            ListElement *temp = oldTable[i]->getHead();
            while (temp->getNext() != NULL)
            {
                add(temp->getStr(), temp->getElemCounter());
                temp = temp->getNext();
            }
            add(temp->getStr(), temp->getElemCounter());
        }
    }
    delete oldTable;
}

void HashTable::checkOverFlow()
{
    if (LoadFactor > 0.6)
        rebuildTable(2 * hTsize, hash);
}

HashTable::~HashTable()
{
    for (unsigned int i = 0; i < hTsize; i++)
    {
        if (table[i] != NULL)
            delete table[i];
    }
    delete []table;
    delete hash;
}
