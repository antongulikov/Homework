#include "List.h"

List::List() :
{

}

List::~List()
{
	if (size > 0)
		delete head;
}

bool List::isEmpty()
{
	return size == 0;
}

void List::add (string str, unsigned int quantity)
{
	if (size == 0)
	{
		ListElement *temp = new ListElement(str);
		head = temp;
		tail = temp;
		head->elemCounter += quantity;
		size++;
	}
	else
	{
		ListElement *tmp = head;
		while (tmp->next != NULL)
		{
			if (tmp->str == str)
			{
				tmp->elemCounter += quantity;
				return;
			}
			tmp = tmp->next;
		}
		if (tail->str == str)
		{
			tail->elemCounter += quantity;
			return;
		}
		else
		{
			ListElement *temp = new ListElement(str, tail, NULL);
			temp->elemCounter += quantity;
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
}

void List::remove(string str) throw (string)
{
	if (size >= 2)
	{
		if (head->str == str)
		{
			ListElement *toDel = head;
			head = head->next;
			head->prev = NULL;
			toDel->next = NULL;
			delete toDel;
			size--;
			return;
		}
		ListElement *temp = head->next;
		while(temp->next != NULL)
		{
			if (temp->str == str)
			{
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				delete temp;
				size--;
				return;
			}
			temp = temp->next;
		}
		if (tail->str == str)
		{
			ListElement *toDel = tail;
			tail = tail->prev;
			tail->next = NULL;
			size--;
			delete toDel;
			return;
		}
	}

	else if (size == 1)
	{
		delete head;
		size--;
		return;
	}
	else
		throw string("No such word");
}

bool List::exists(string str)
{
	ListElement *temp = head;
	while (temp->next != NULL)
	{
		if (str == temp->str)
		{
			return true;
		}
		else
			temp = temp->next;
	}
	return temp->str == str;
}
