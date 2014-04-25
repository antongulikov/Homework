#pragma once
#include <set>
#include "hashfunction.h"

/// class for hash table
class HashTable
{
public:
	HashTable(long long pw, long long base);
	~HashTable();
	/// insert element in HashTable
	void insert(string const s);
	/// find element in HashTable
	bool find(string const s);
	/// erase element from HashTable
	void erase(string const s);
	/// count loadFactor of HashTable
	double loadFactor();
	/// find the number of conflict in hash table
	int numberOfConflict();
	/// find the the most long chain in hashArray 
	int longestConflict();
	/// method for changing hash function
	void changeHashFunction(HashFunction *newHashFunction);
	
private:
	set <string> *hashArray;
	HashFunction *hashFunction;
	int hashBase;
};

