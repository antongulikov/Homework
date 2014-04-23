#pragma once
#include <string>
using namespace std;
/// Class for Hash Fucntion
class HashFunction
{

public:
	HashFunction(long long pw, long long base);
	
	/// Method which returns a value of string's hash
	long long getHash(string s);
		
private :
	long long base;
	long long pw;
};

