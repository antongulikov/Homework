#include "HashFunction.h"

HashFunction::HashFunction()
{	
}

int HashFunction::getCode(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if ((ch >= 'A' && ch <= 'Z')) 
        return ch - 'A' + 10;
    return
		ch - 'a' + 36;
	return 0;
}

int HashFunction::pow(int a, int b)
{
	int result = 1;
	int tmp = 1;
	while (b)
	{
		result = result * result;
		if (b & 1)
		{
			result *= tmp;
		}
		tmp *= a;
		b >>= 1;					
	}
	return result;	
}

SumHash::~SumHash()
{
	
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

XorHash::~XorHash()
{	
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
