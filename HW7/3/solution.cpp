#include <iostream>
#include "stringXXX.h"
#include "htable.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace scorpion;
using namespace std;

// Первый файл input1.txt. Второй - input2.txt. Ответ в output.txt

int main()
{	
	FILE * input = fopen("input.txt", "r");
	freopen ("output.txt", "w", stdout);
	HashTable *myHashTable = createTable();
	char ch = '\0';
	char *cha = new char[2];
	char *buffer = new char[base];
	memset(buffer, '\0', base);
	int n = 0;
	while (! feof (input) ){
		fgets(cha, 2, input);
		ch = cha[0];
		if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')){
			buffer[n++] = ch;
			continue;
		} else if (n > 0) {
			char *str = new char[n + 2];
			memset(str,'\0', n + 2);
			for (int i = 0; i < n; i++)
				str[i] = buffer[i];
			n = strlen(str);
			while (!( ('a' <= str[n - 1] && str[n - 1] <= 'z') || ('A' <= str[n - 1] && str[n - 1] <= 'Z'))){
				str[n - 1] = '\0';
				n--;
			}
			addToHashTable(myHashTable, createString(str, n));	
			n = 0;
			delete[] str;
		}
	}
	fclose(input);
	printStatistic(myHashTable);
	clearTable(myHashTable);
	delete[] buffer;
	delete[] cha;
	return 0;
}

