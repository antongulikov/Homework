#include "linlist.h"
#include <iostream>

using namespace std;

LinList::LinList() : head(NULL), last(NULL)
{    
}

void LinList :: push(int value){
    if (head == NULL){
            ListElement *tmp = new ListElement();
            tmp->value = value;
            tmp->next = NULL;
            head = tmp;
            last = head;
    } else{
		ListElement *tmp = new ListElement();
        tmp->value = value;
        tmp->next = NULL;            
		last->next = tmp;
		last = tmp;
    }
}

void LinList :: pop(int value){
	ListElement *tmp = head;
	ListElement *prev = NULL;
	while (tmp != NULL){
		if (tmp->value == value && prev == NULL){
			head = head->next;
			delete tmp;
			return;
		}
		if (tmp->value == value && prev != NULL){
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
	while (tmp != NULL){
		if (tmp->value == value)
			return true;
		tmp = tmp->next;	
	}
	return false;
}

void  LinList :: print(){
	ListElement *tmp = head;
	while (tmp != NULL){
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
int LinList :: size(){
	ListElement *tmp = head;
	int ans = 0;
	while (tmp != NULL){
		ans++;
		tmp = tmp->next;
	}
	return ans;
}

LinList :: ~LinList(){
	while (head != NULL){
		ListElement *tmp = head->next;
		delete head;
		head = tmp;
	}
	delete last;
}
