#pragma once
#include "list.h"
/// Class for Linked List 
class LinList : public List
{
	public:
		LinList();
		~LinList();
		bool find(int value);
		void print();
		int getSize();
		
	protected :
		/// Push element in  list
		void push(int value);
		/// Pop element from list
		void pop(int value);		
    
	private :
    
		struct ListElement {
			int value;
			ListElement *next;
		};		
		ListElement *head;
};


