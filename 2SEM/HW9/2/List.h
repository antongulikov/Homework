#pragma once

#include "ListElement.h"
/** List class interface.
    It allows to add, search, or remove std::string in it */

class List
{
public:
    List();
    ~List();
    bool isEmpty();
    void add(string str, unsigned int quantity);
    void remove(string str) throw (string);
    bool exists(string str);
    
    ListElement* getHead()
    {
        return head;    
    }
    
    void setHead(ListElement *tmp)
    {
        head = tmp;
    }
    
    ListElement* getTail()
    {
        return tail;
    }
    
    void setTail(ListElement *tmp)
    {
        tail = tmp;
    }
    
    unsigned int getSize()
    {
        return size;
    }
    
    void setSize(unsigned int newSize)
    {
        size = newSize;
    }

private:
    ListElement *head;
    ListElement *tail;
    unsigned int size;
};
