#ifndef STRINGXXX_H
#define STRINGXXX_H
#pragma once

/*

Anton Gulikov / Scorpion

������� �� ������ � ������� stringXXX.h

����� ���������� � ����.


1. stringXXX *createString(char *s, int n)
   ������ ������ � ����� �����.
   ���� ������ �����, �� ���������� ������ ������ ������� n ����� ���������� ������ ������ strlen(s).
2. void deleteString(stringXXX *string);
   ��������, ����� ������ ���������, ��������� ������ �� ������.
3. int length(stringXXX *string);
   ��������� ����� ������.
4. stringXXX *clone(stringXXX *string);
   ��������� ������ ����� ������ string.
5. void addFristToSecond(stringXXX *first, stringXXX *&second);
   ���������� � ����� ������ second ������ first 
6. bool isEqual(stringXXX *first, stringXXX *second);
   True - ���� ������ �����, ����� False.
7. stringXXX *substring(stringXXX *string, int start, int finish);
   ��������� ��������� �� start �� finish, ���������� � ����.
8. char *stringToChar(stringXXX *string);
9. void print(stringXXX *string);
   �������� ������.
10. getsSympol(stringXXX *string, int pos)
    ��������� ������ �� ������� pos, ��� '\0' ���� pos > length(string).

*/

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
