#pragma once

#include "ListElement.h"

class List
{
public:
    List();
    ~List();
    bool isEmpty();
    void add(string str, unsigned int quantity);
    void remove(string str) throw (string);
    bool exists(string str);
    ListElement *head;
    ListElement *tail;
    unsigned int size;
};
