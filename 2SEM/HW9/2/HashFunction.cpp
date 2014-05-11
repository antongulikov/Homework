#include "HashFunction.h"

int HashFunction::getCode(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch + 11;
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return ch - 13;
	return 0;
}

unsigned int SumHash::hash(string s)
{
	unsigned int hashCode = 0;
	int factor = 1;
	for (int i = 0; s[i] != '\0'; i++)
	{
		int code = getCode(s[i]);
		hashCode += code * pow(base, factor);
		factor++;
	}
	return (hashCode > 0)? hashCode : 0 - hashCode;
}

unsigned int XorHash::hash(string s)
{
	unsigned int hashCode = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		int code = getCode(s[i]);
		hashCode += code ^ mask;
	}
	return (hashCode > 0)? hashCode : 0 - hashCode;
}
