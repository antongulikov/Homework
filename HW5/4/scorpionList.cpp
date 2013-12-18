#include "scorpionList.h"
#include <stdio.h>
#include <string.h>

namespace scorpion{


	List* createList(){
		List * newList = new List;
		newList->head = nullptr;
		return newList;
	}

	ListElement* createElement(char *key, char *value){
		ListElement* newElement = new ListElement;
		newElement->key = key;
		newElement->value = value;
		newElement->next = nullptr;
		return newElement;
	}

	void addToList(char *key, char *value, ListElement *position){
		ListElement *newElement = createElement(key, value);
		newElement->next = position->next;
		position->next = newElement;
	}

	void removeFromList(ListElement *&position){
		if (position == nullptr)
			return;
		if (position->next == nullptr) 
			return;
		ListElement * deleteElement = position->next;
		position->next = position->next->next;
		delete[] deleteElement->key;
		delete[] deleteElement->value;
		delete deleteElement;
	}

	void print(char *s){
		for (int i = 0; i < strlen(s) && s[i] != '\n' && s[i] != '\0'; i++)
			printf("%c", s[i]);
		return;
	}

	bool equal(char *s1, char *s2){
		int n = strlen(s1);
		int m = strlen(s2);
		while (m > 0 && s2[m-1] == '\0' || s2[m-1] == '\n')
			m--;
		while (n > 0 && s1[n-1] == '\0' || s1[n-1] == '\n')
			n--;
		if (n != m)
			return false;
		for (int i = 0; i < n; i++)
			if (s1[i] != s2[i])
				return false;
		return true;
	}

	char *findElement(List *myList, char *key){
		ListElement *currentPosition = myList->head->next;
		while (currentPosition != nullptr){
			if (equal(currentPosition->key, key))
				return currentPosition->value;
			if (equal(currentPosition->value, key))
				return currentPosition->key;
			currentPosition = currentPosition->next; 
		}
		return "No Founded !!!";
	}

	void printList(List *myList){
		ListElement *currentPosition = myList->head->next;
		while (currentPosition != nullptr){
			print(currentPosition->key);
			printf("\n");
			print(currentPosition->value);
			currentPosition = currentPosition->next;
			if (currentPosition != nullptr)
				printf("\n");
		}		
	}	

	ListElement * getFirstElementLessThan(ListElement * start, char *key){
		ListElement * currentElement = start;
		while (currentElement->next != nullptr && strcmp(currentElement->next->key, key) == -1 ){
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

	void insertInData(List *myList, char *key, char *value){
		if (myList->head == nullptr){
			myList->head->next = createElement(key, value);
			return;
		}
		ListElement *currentElement = getFirstElementLessThan(myList->head, key);
		addToList(key, value, currentElement);			
	}

}