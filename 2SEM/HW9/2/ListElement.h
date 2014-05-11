#pragma once

#include <stdlib.h>
#include <iostream>
using namespace std;

/// Class for ListElement

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
    
    ListElement *getPrev()
    {
        return prev;
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
    
    void setPrev(ListElement *newPrev)
    {
        prev = newPrev;
    }
    
    void setNext(ListElement *newNext)
    {
        next = newNext;
    }

private:
    string str;
    ListElement *prev;
    ListElement *next;
    int elemCounter;    
};
