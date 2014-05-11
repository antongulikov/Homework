#pragma once

#include <iostream>
#include <math.h>
using namespace std;

/// Clases for hashFunctions

class HashFunction
{
public:
    virtual unsigned int hash(string s) = 0;
    virtual ~HashFunction(){}
    protected:
    int getCode(char ch);
};


class XorHash : public HashFunction
{
public:
    XorHash() : mask(0xD3) {}
    ~XorHash(){}
    unsigned int hash(string s);
private:
    const char mask;

};


class SumHash : public HashFunction
{
public:
    SumHash() : base(13) {}
    ~SumHash(){}
    unsigned int hash(string s);
private:
    const int base;
};
