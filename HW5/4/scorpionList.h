#pragma once

namespace scorpion
{

	struct ListElement{
		char *key;
		char *value;
		ListElement *next;
	};

	struct List{
		ListElement *head;
	};

	List* createList(); // создаёт новый лист

	ListElement* createElement(char *key, char *value); // создаёт новый елемент

	void addToList(char *key, char *value, ListElement *position); // добавляет новый елемент после position

	void removeFromList(ListElement *&position); // удаляет следующий елемент после position

	void printList(List *myList); //  Передать указатель на следующий после защитника
	
	void insertInData(List *myList, char *key, char *value);

	void deleteList(List *mylist); // удаляет из памяти все елементы после этого

	ListElement* getFirstElementLessThan(ListElement *start, char *key);
	
	char *findElement(List *myList, char *key);

	void print(char *s);

}
