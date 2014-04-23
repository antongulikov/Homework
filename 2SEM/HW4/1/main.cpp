#include <iostream>
#include "hashtable.h"
#include "hashfunctiontest.h"
#include "hashtabletest.h"

using namespace std;

int main()
{
	HashFunctionTest hashFunctionTest;
	QTest :: qExec(&hashFunctionTest);
	HashTableTest hashTableTest;
	QTest :: qExec(&hashTableTest);
	
	HashTable *hTable = new HashTable(10, 1);
	for (int i = 0; i < 100; i++){
		string tmp = "";
		int x = i % 10;
		while (x){
			tmp += ((char)((int)'a' + x % 10));
			x /= 10;
		}
		hTable->insert(tmp);		
	}
	
	cout << hTable->loadFactor() << " " << hTable->longestConflict() << " " << hTable->numberOfConflict();
	delete hTable;
	return 0;
}

