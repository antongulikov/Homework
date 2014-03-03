#pragma once

namespace scorpion
{

	struct ListElement{
		int power;
		int ratio;
		ListElement *next;
	};

	struct List{
		ListElement *head;
	};

	List* createList(); // создаёт новый лист

	ListElement* createElement(int key); // создаёт новый елемент

	void addToList(int power, int ratio, List *myList); // добавляет новый елемент после position

	void removeFromList(ListElement *position); // удаляет следующий елемент после position

	void printList(List *myList); //  Передать указатель на следующий после защитника

	void deleteList(List *mylist); // удаляет из памяти все елементы после этого

	double value(List *mylist, double x);

	bool equals(List *first, List *second);

	List *add(List *first, List *second);

	ListElement* getFirstElementLessThan(ListElement *start, int power, int ratio);

	void readPolynom(List *polynom);

}
