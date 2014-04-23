#include "hashfunction.h"

HashFunction::HashFunction(long long pw, long long base) : pw(pw), base(base) 
{
}

long long HashFunction::getHash(string s)
{
	long long result = 0;
	for (int i = 0; i < s.size(); i++){
		result = result * pw + s[i];
		result %= base;
	}
	return result;
}
