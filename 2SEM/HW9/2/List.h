#pragma once

#include "ListElement.h"
/// Class for List

class List
{
public:
    List();
    ~List();
    bool isEmpty();
    void add(string str, unsigned int quantity);
    void remove(string str) throw (string);
    bool exists(string str);
	
	ListElement *getHead();
	ListElement *getTail();
	unsigned int getSize();
	
private:
    ListElement *head;
    ListElement *tail;
    unsigned int size;
    void setTail(ListElement *tmp);
	void setHead(ListElement *tmp);
	void setSize(unsigned int newSize);
};
