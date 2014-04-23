#include "hashtable.h"

HashTable::HashTable(long long pw, long long base) : hashBase(base)
{
	hashArray = new set<string>[base];
	for (int i = 0; i < base; i++)
		hashArray[i].clear();
	hashFunction = new HashFunction(pw, base);
}

HashTable::~HashTable()
{
	for (int i = 0; i < hashBase; i++)
		hashArray[i].clear();
	delete[] hashArray;
	delete hashFunction;
}

void HashTable::insert(string s)
{
	long long hash = hashFunction->getHash(s);
	hashArray[hash].insert(s);
}

bool HashTable::find(string s)
{
	long long hash = hashFunction->getHash(s);
	return (hashArray[hash].find(s) != hashArray[hash].end());
}

void HashTable::erase(string s)
{
	long long hash = hashFunction->getHash(s);
	hashArray[hash].erase(s);
}

double HashTable::loadFactor()
{
	double result = 0;
	for (int i = 0; i < hashBase; i++)
		result = result + hashArray[i].size();
	return result / (0. + hashBase);
}

int HashTable::numberOfConflict()
{
	int result = 0;
	for (int i = 0; i < hashBase; i++)
		result += (hashArray[i].size() > 1);
	return result;
}

int HashTable::longestConflict()
{
	int result = 0;
	for (int i = 0; i < hashBase; i++)
		result = (result < hashArray[i].size() ? hashArray[i].size() : result);
	return result;
}

void HashTable::changeHashFunction(long long pw, long long base)
{
	delete hashFunction;
	hashFunction = new HashFunction(pw, base);
	set<string> *newArray = new set<string>[base];
	for (int i = 0; i < base; i++)
		newArray[i].clear();
	for (int i = 0; i < hashBase; i++){
		for (set<string> :: iterator it = hashArray[i].begin(); it != hashArray[i].end(); it++)
			newArray[hashFunction->getHash(*it)].insert(*it);
		hashArray[i].clear();		
	}
	delete[] hashArray;
	hashBase = base;
	hashArray = newArray;
}


