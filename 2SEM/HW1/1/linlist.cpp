#include "linlist.h"
#include <iostream>

using namespace std;

LinList::LinList() : head(nullptr), last(nullptr)
{    
}

void LinList :: push(int value){
	if (head == nullptr){
		ListElement *tmp = new ListElement();
		tmp->value = value;
		tmp->next = nullptr;
		head = tmp;
		last = head;
	} else{
		ListElement *tmp = new ListElement();
		tmp->value = value;
		tmp->next = nullptr;            
		last->next = tmp;
		last = tmp;
	}
}

void LinList :: pop(int value){
	ListElement *tmp = head;
	ListElement *prev = nullptr;
	while (tmp != nullptr){
		if (tmp->value == value && prev == nullptr){
			if (tmp->next == nullptr){
				last = prev;
			}			
			head = head->next;	
			delete tmp;
			return;
		}
		if (tmp->value == value && prev != nullptr){
			if (tmp->next == nullptr){
				last = prev;
			}
			prev->next = tmp->next;
			delete tmp;
			return;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
bool LinList :: find(int value){
	ListElement *tmp = head;
	while (tmp != nullptr){
		if (tmp->value == value)
			return true;
		tmp = tmp->next;	
	}
	return false;
}

void  LinList :: print(){
	ListElement *tmp = head;
	while (tmp != nullptr){
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
int LinList :: size(){
	ListElement *tmp = head;
	int ans = 0;
	while (tmp != nullptr){
		ans++;
		tmp = tmp->next;
	}
	return ans;
}

LinList :: ~LinList(){
	while (head != nullptr){
		ListElement *tmp = head->next;
		delete head;
		head = tmp;
	}
	if (last != nullptr)
		delete last;
}
