#ifndef HTABLE_H
#define HTABLE_H
#pragma once

#include "stringXXX.h"


namespace scorpion {

	const int base = 100003;

	struct HashCell{
		StringXXX *key;
		int howMuch;
		HashCell *next;
	};

	struct HashTable{
		HashCell *Cells[base];
	};

	HashTable *createTable();

	void addToHashTable(HashTable *hashTable, StringXXX *key);

	void printStatistic(HashTable *hashTable);

	void clearTable(HashTable *hashTable);

	int countNumberOfWord(HashTable *hashTable, StringXXX *key);

}

#endif // HTABLE_H
