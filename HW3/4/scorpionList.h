#pragma once

namespace scorpion
{

	struct ListElement{
		int value;
		ListElement *next;
	};

	struct List{
		ListElement *head;
	};

	List* createList(); // создаёт новый лист

	ListElement* createElement(int key); // создаёт новый елемент

	void addToList(int key, ListElement *position); // добавляет новый елемент после position

	void removeFromList(ListElement *position); // удаляет следующий елемент после position

	void printList(List *myList); //  Передать указатель на следующий после защитника

	void deleteList(List *mylist); // удаляет из памяти все елементы после этого

	ListElement* getFirstElementLessThan(ListElement *start, int value);

}
