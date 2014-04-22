#include "linlist.h"
#include <iostream>

using namespace std;

LinList::LinList() : head(nullptr)
{    
}

void LinList :: push(int value){
	ListElement *tmp = new ListElement;
	tmp->value = value;
	tmp->next = nullptr;
	if (head == nullptr)
		head = tmp;		
	else{
		tmp->next = head;
		head = tmp;
	}
}

void LinList :: pop(int value){
	if (head == nullptr) return;
	if (head->value == value){
		ListElement *tmp = head;
		head = head->next;
		delete tmp;
		return;
	}
	ListElement *tmp = head;
	while (tmp->next != nullptr && tmp->next->value != value)
		tmp = tmp->next;
	if (tmp->next == nullptr) return;
	ListElement *del = tmp->next;
	tmp->next = tmp->next->next;
	delete del;
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
int LinList :: getSize(){
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
	delete head;	
}
