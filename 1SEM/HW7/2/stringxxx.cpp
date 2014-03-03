#include "stringxxx.h"
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

namespace scorpion {

	StringXXX *createString(char const *s, int n){
		StringXXX *newString = new StringXXX;
		if (strlen(s) > 0) 
			n = strlen(s);
		newString->sizeString = n;
		newString->buffer = new char[n + 1];
		memset(newString->buffer, '\0', (n + 1));
		if (strlen(s) > 0)
			for (int i = 0; i < n; i++)
				newString->buffer[i] = s[i];
		
		return newString;
	}

	void deleteString(StringXXX *string){
		delete[] string->buffer;
		delete string;
	}

	int length(StringXXX *string){
		return string->sizeString;
	}

	StringXXX *clone(StringXXX *string){
		StringXXX *cloneString = createString(string->buffer, length(string));
		return cloneString;
	}

	void addFristToSecond(StringXXX *first, StringXXX *&second){
		int n = first->sizeString;
		int m = second->sizeString;
		StringXXX *newString = createString("\0", n+m);
		for (int i = 0; i < m; i++)
			newString->buffer[i] = second->buffer[i];
		for (int i = 0; i < n; i++)
			newString->buffer[m + i] = first->buffer[i];
		deleteString(second);
		second = newString;
	}

	bool areEqual(StringXXX *first, StringXXX *second){
		int n = first->sizeString;
		int m = second->sizeString;
		if (n != m)
			return false;
		for (int i = 0; i < n; ++i)
			if (first->buffer[i] != second->buffer[i])
				return false;
		return true;
	}

	StringXXX *substring(StringXXX *string, int start, int finish){
		StringXXX *res = createString("\0", finish - start + 1);
		for (int i = start; i <= finish; i++)
			res->buffer[i - start] = string->buffer[i];
		return res;
	}

	char *stringToChar(StringXXX *string){
		char *res = new char[string->sizeString + 1];
		memset(res, '\0', string->sizeString + 1);
		for (int i = 0; i < string->sizeString; i++)
			res[i] = string->buffer[i];
		return res;
	}

	void print(StringXXX *string){
		for (int i = 0; i < string->sizeString; i++){
			if (string->buffer[i] == '\0')
				break;
			printf("%c", string->buffer[i]);
		}
		printf("\n");
	}

	char getsSymbol(StringXXX *string, int pos){
		if (pos > length(string))
			return '\0';
		return string->buffer[pos];
	}

	bool isEmpty(StringXXX *string){
		return string->sizeString == 0;
	}
}
