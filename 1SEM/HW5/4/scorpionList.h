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

	List* createList(); // ������ ����� ����

	ListElement* createElement(char *key, char *value); // ������ ����� �������

	void addToList(char *key, char *value, ListElement *position); // ��������� ����� ������� ����� position

	void removeFromList(ListElement *&position); // ������� ��������� ������� ����� position

	void printList(List *myList); //  �������� ��������� �� ��������� ����� ���������
	
	void insertInData(List *myList, char *key, char *value);

	void deleteList(List *mylist); // ������� �� ������ ��� �������� ����� �����

	ListElement* getFirstElementLessThan(ListElement *start, char *key);
	
	char *findElement(List *myList, char *key);

	void print(char *s);

}
