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

	List* createList(); // ������ ����� ����

	ListElement* createElement(int key); // ������ ����� �������

	void addToList(int power, int ratio, List *myList); // ��������� ����� ������� ����� position

	void removeFromList(ListElement *position); // ������� ��������� ������� ����� position

	void printList(List *myList); //  �������� ��������� �� ��������� ����� ���������

	void deleteList(List *mylist); // ������� �� ������ ��� �������� ����� �����

	double value(List *mylist, double x);

	bool equals(List *first, List *second);

	List *add(List *first, List *second);

	ListElement* getFirstElementLessThan(ListElement *start, int power, int ratio);

	void readPolynom(List *polynom);

}
