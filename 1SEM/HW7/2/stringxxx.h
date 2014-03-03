#ifndef STRINGXXX_H
#define STRINGXXX_H
#pragma once

/*

Anton Gulikov / Scorpion

Пособие по работе с модулем stringXXX.h

Везде индексация с нулю.


1. stringXXX *createString(char *s, int n)
   Подаёте строку и любое число.
   Если строка пуста, то создасться пустая строка длинной n иначе создасться строка длиной strlen(s).
2. void deleteString(stringXXX *string);
   Наверное, самая важная процедура, удалающая строку из памати.
3. int length(stringXXX *string);
   Возращает длину строки.
4. stringXXX *clone(stringXXX *string);
   Возращает точную копию строки string.
5. void addFristToSecond(stringXXX *first, stringXXX *&second);
   Дописывает в конец строки second строку first 
6. bool isEqual(stringXXX *first, stringXXX *second);
   True - если строки равны, иначе False.
7. stringXXX *substring(stringXXX *string, int start, int finish);
   Возращает подтсроку со start до finish, индексация с нуля.
8. char *stringToChar(stringXXX *string);
9. void print(stringXXX *string);
   Печатает строку.
10. getsSympol(stringXXX *string, int pos)
    Возращает символ на позиции pos, или '\0' если pos > length(string).

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
