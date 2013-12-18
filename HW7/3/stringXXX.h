#ifndef STRINGXXX_H
#define STRINGXXX_H
#pragma once


namespace scorpion {

	struct StringXXX{
		int sizeString;
		char *buffer;
	};

	StringXXX *createString(char const *s, int n);

	void deleteString(StringXXX *string);

	int length(StringXXX *string);

	StringXXX *clone(StringXXX *string);

	void addFristToSecond(StringXXX *first, StringXXX *&second);

	bool areEqual(StringXXX *first, StringXXX *second);

	StringXXX *substring(StringXXX *string, int start, int finish);

	char *stringToChar(StringXXX *string);

	void print(StringXXX *string);

	char getsSymbol(StringXXX *string, int pos);

	bool isEmpty(StringXXX *sting);
}

#endif // STRINGXXX_H
