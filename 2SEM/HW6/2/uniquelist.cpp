#include "uniquelist.h"

UniqueList::UniqueList() : head(nullptr), size(0)
{
}

UniqueList :: ~UniqueList(){
	while (head != nullptr){
		size--;
		ListElement *tmp = head->next;
		delete head;
		head = tmp;			
	}	
}

int UniqueList :: getSize(){
	return size;
}

bool UniqueList :: find(int value){
	ListElement *tmp = head;
	
	while (tmp != nullptr){
		if (tmp->value == value)		
			return true;
		tmp = tmp->next;			
	}
	
	return false;
}

void UniqueList :: insert(int value){
	if (find(value))
		throw DuplicateException("Already exists!");
		
	ListElement *newElement = new ListElement;
	
	size++;
	newElement->value = value;
	newElement->next = head;
	head = newElement;			
}

int UniqueList :: erase(int value){
	if (! find(value))
		throw ExistException("Element doesn't exists!");
		
	ListElement *tmp = head;
	ListElement *prev = nullptr;
	
	while (tmp->value != value){
		prev = tmp;
		tmp = tmp->next;
	}
	size--;
	if (prev == nullptr){
		tmp = head->next;
		delete head;
		head = tmp;
		return value;					
	}
	prev->next = tmp->next;
	delete tmp;
	return value;
}
