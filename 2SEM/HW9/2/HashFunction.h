#pragma once

#include <iostream>
#include <math.h>
using namespace std;

class HashFunction
{
public:
    virtual unsigned int hash(string s) = 0;
protected:
    int getCode(char ch);
};


class XorHash : public HashFunction
{
public:
    XorHash() : mask(0xD3) {}
    unsigned int hash(string s);
private:
    const char mask;

};


class SumHash : public HashFunction
{
public:
    SumHash() : base(13) {}
    unsigned int hash(string s);
private:
    const int base;
};
