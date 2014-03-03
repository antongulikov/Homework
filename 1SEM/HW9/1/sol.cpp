#include <iostream>
#include "stringXXX.h"
#include "htable.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>

using namespace scorpion;
using namespace std;

// Первый файл input1.txt. Второй - input2.txt. Ответ в output.txt

int main()
{	
	if ( ifstream("input1.txt") == nullptr){
		printf("Not found then first file!\n");
		return 0;
	}

	if (ifstream("input2.txt") == nullptr){
		printf("Not found the second file!");
		return 0;
	}
	freopen("output.txt", "w", stdout);
	FILE *input = fopen("input1.txt", "r");
	HashTable *myHashTable = createTable();
	char *buffer = new char[base + 5];
	memset(buffer, '\0', base + 5);
	while (!feof(input)){
		fgets(buffer, base, input);
		addToHashTable(myHashTable, createString(buffer, base));
	}
	fclose(input);
	input = fopen("input2.txt", "r");
	while (!feof(input)){
		fgets(buffer, base, input);
		if (countNumberOfWord(myHashTable, createString(buffer, base)) > 0)
			printf("%s\n", buffer);			
	}
	fclose(input);
	clearTable(myHashTable);
	delete[] buffer;
	return 0;
}

