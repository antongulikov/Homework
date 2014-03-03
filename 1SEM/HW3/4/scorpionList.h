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

	List* createList(); // ������ ����� ����

	ListElement* createElement(int key); // ������ ����� �������

	void addToList(int key, ListElement *position); // ��������� ����� ������� ����� position

	void removeFromList(ListElement *position); // ������� ��������� ������� ����� position

	void printList(List *myList); //  �������� ��������� �� ��������� ����� ���������

	void deleteList(List *mylist); // ������� �� ������ ��� �������� ����� �����

	ListElement* getFirstElementLessThan(ListElement *start, int value);

}
