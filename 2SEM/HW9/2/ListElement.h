#pragma once

#include <stdlib.h>
#include <iostream>
using namespace std;

class ListElement
{
public:
    ListElement(string s) : str(s), prev(NULL), next(NULL), elemCounter(0) {}
    ListElement(string s, ListElement *prevElem, ListElement *nextElem) : str(s), prev(prevElem),
        next(nextElem), elemCounter(0)  {}


    ~ListElement()
    {
        if (next != NULL)
            delete next;
    }
public:
    string str;
    ListElement *prev;
    ListElement *next;
    int elemCounter;
};
