#include "htable.h"
#include "stringXXX.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

namespace scorpion{

	HashTable *createTable(){

		HashTable *newTable = new HashTable;
		for (int i = 0; i < base; i++)
			newTable->cells[i] = nullptr;
		return newTable;
	}

	HashCell *createCell(StringXXX *string){
		HashCell *newCell = new HashCell;
		newCell->next = nullptr;
		newCell->key = string;
		newCell->howMuch = 0;
		return newCell;
	}

	int getHash(StringXXX *string){
		int res = 0;
		int p = 1;
		for (int i = 0; i < length(string); i++){
			res += (p * (string->buffer[i] -'A')) % base;
			res %= base;
			p *= 101;
			p %= base;
		}
		return res;
	}

	HashCell *addCell(HashCell *cell, StringXXX *key){
		HashCell *tmp = cell;
		while (tmp != nullptr){
			if (areEqual(tmp->key, key)){
				tmp->howMuch++;
				deleteString(key);
				return cell;
			}
			tmp = tmp->next;
		}
		HashCell *newCell = createCell(key);
		newCell->next = cell;
		newCell->howMuch++;
		return newCell;
	}

	void addToHashTable(HashTable *hashTable, StringXXX *key){
		int position = getHash(key);
		if (position < 0){
			print(key);
			exit(0);
		}
		hashTable->cells[position] = addCell(hashTable->cells[position], key);
	}

	int countNumberOfWord(HashTable *hashTable, StringXXX *key){
		int position = getHash(key);
		HashCell *tmp = hashTable->cells[position];
		while (tmp != nullptr){
			if (areEqual(tmp->key, key))
				return tmp->howMuch;
			tmp = tmp->next;
		}
		return 0;
	}

	int findLength(HashCell *cell){
		HashCell *tmp = cell;
		int res = 0;
		while (tmp != nullptr){
			res++;
			tmp = tmp->next;
		}
		return res;
	}

	int findNumberWord(HashCell *cell){
		HashCell *tmp = cell;
		int res = 0;
		while (tmp != nullptr){
			res += tmp->howMuch;
			tmp = tmp->next;
		}
		return res;
	}

	float findLoadFactor(HashTable *hashTable){
		float res = 0;
		for (int i = 0; i < base; i++)
			res += findNumberWord(hashTable->cells[i]) / (0.0 + base);
		return res;
	}

	float middleLength(HashTable *hashTable){
		float res = 0;
		for (int i = 0; i < base; i++)
			res += findLength(hashTable->cells[i]) / (0.0 + base);
		return res;
	}

	int findMaxLength(HashTable *hashTable){
		int res = -1;
		for (int i = 0; i < base; i++)
			res = max(res, findLength(hashTable->cells[i]));
		return res;
	}

	void printAllWords(HashTable *hashTable, int len){
		for (int i = 0; i < base; i++)
			if (findLength(hashTable->cells[i]) == len){
				HashCell *tmp = hashTable->cells[i];
				while (tmp != nullptr){
					print(tmp->key);
					tmp = tmp->next;
				}

			}
	}

	int numOfAddedWords(HashTable *hashTable){
		int res = 0;
		for (int i = 0; i < base; i++)
			res += findLength(hashTable->cells[i]);
		return res;
	}

	int numberOfEmptyCell(HashTable *hashTable){
		int res = 0;
		for (int i = 0; i < base; i++)
			res += (findLength(hashTable->cells[i]) == 0);
		return res;
	}


	void printStatistic(HashTable *hashTable){
		printf("Load Factor is %.10f\n", findLoadFactor(hashTable));
		printf("The middle lenght is %.10f\n", middleLength(hashTable));
		printf("Max chain's length is %d\n", findMaxLength(hashTable));
		printf("Words in a max chain : ");
		printAllWords(hashTable, findMaxLength(hashTable));
		printf("The number of different added words is %d\n", numOfAddedWords(hashTable));
		printf("The number of empty cell's is %d\n", numberOfEmptyCell(hashTable));
	}

	void clearCell(HashCell *currentCell){
		if (currentCell == nullptr)
			return;
		clearCell(currentCell->next);
		deleteString(currentCell->key);
		delete currentCell;
	}

	void clearTable(HashTable *hashTable){
		for (int i = 0; i < base; i++){
			clearCell(hashTable->cells[i]);
		}
		delete hashTable;
	}
}

