#pragma once

#include <iostream>
using namespace std;
/// Classes for hashFunctions
class HashFunction
{
public:
	HashFunction();	
    virtual unsigned int hash(string s) = 0;
    //virtual ~HashFunction() = 0;
protected:
    int getCode(char ch);
    int pow(int a, int b);
};


class XorHash : public HashFunction
{
public:
    XorHash() : mask(0xD3) {}
    ~XorHash();
    unsigned int hash(string s);
private:
    const char mask;

};


class SumHash : public HashFunction
{
public:
    SumHash() : base(13) {}
    ~SumHash();
    unsigned int hash(string s);
private:
    const int base;
};
