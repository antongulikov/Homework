#pragma once
#include <list.h>

class LinList : public List
{
    public:
        LinList();
        ~LinList();
        void push(int value);
        void pop(int value);
        bool find(int value);
        void print();
        int size();
    
    private :
    
		struct ListElement {
				int value;
				ListElement *next;
		};	
	
		ListElement *head;
		LiseElement *last;
};


