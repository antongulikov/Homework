#pragma once

#include <stdlib.h>
#include <iostream>
using namespace std;

/** ListElement class interface.
    Each element contains std::string and a counter to count repetitions of string */

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
    
    ListElement *getNext()
    {
        return next;
    }
    
    void setNext(ListElement *newNext)
    {
        next = newNext;
    }
    
    ListElement *getPrev()
    {
        return prev;
    }
    
    void setPrev(ListElement *newPrev)
    {
        prev = newPrev;
    }
    
    string getStr()
    {
        return str;
    }
    
    void setStr(string newStr)
    {
        str = newStr;
    }
    
    int getElemCounter()
    {
        return elemCounter;
    }
    
    void setElemCounter(int newElemCounter)
    {
        elemCounter = newElemCounter;
    }
    

private:
    string str;
    ListElement *prev;
    ListElement *next;
    int elemCounter;
};
