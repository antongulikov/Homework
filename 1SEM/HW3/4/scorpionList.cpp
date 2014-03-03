#include "scorpionList.h"
#include <stdio.h>

namespace scorpion{


	List* createList(){
		List * newList = new List;
		newList->head = nullptr;
		return newList;
	}

	ListElement* createElement(int key){
		ListElement* newElement = new ListElement;
		newElement->value = key;
		newElement->next = nullptr;
		return newElement;
	}

	void addToList(int key, ListElement *position){
		ListElement *newElement = createElement(key);
		newElement->next = position->next;
		position->next = newElement;
	}

	void removeFromList(ListElement *position){
		if (position->next == nullptr) 
			return;
		ListElement * deleteElement = position->next;
		position->next = position->next->next;
		delete deleteElement;
	}

	void printList(List *myList){
		ListElement *currentPosition = myList->head->next;
		while (currentPosition != nullptr){
			printf("%d ", currentPosition->value);
			currentPosition = currentPosition->next;
		}		
	}

	ListElement * getFirstElementLessThan(ListElement * start, int value){
		ListElement * currentElement = start;
		while (currentElement->next != nullptr && currentElement->next->value < value){
			currentElement = currentElement->next;
		}
		return currentElement;				
	}

	void deleteList(List *myList){
		while (myList->head->next != nullptr){
			removeFromList(myList->head);
		}
		delete myList->head;
		delete myList;
	}

}
