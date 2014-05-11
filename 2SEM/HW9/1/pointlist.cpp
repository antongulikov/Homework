#include <iostream>
#include "pointlist.h"

PList::PList() : list()
{
	this->first = new ListElement;
	this->first->next = nullptr;

}

PList::~PList()
{
	deleteList();
}

void PList::addValue(int value)
{
	ListElement *tmp = this->first;
	while (tmp->next != nullptr)
	{ 
		tmp = tmp->next;
	}
	ListElement *addValue = new ListElement;
	addValue->value = value;
	addValue->next = tmp->next;
	tmp->next = addValue;
}

void PList::deleteValue(int numb)
{
	ListElement *tmp = this->first;
	bool delEl = false;
	while ((tmp->next->value != numb) && (tmp->next->next != nullptr))
	{
		tmp = tmp->next;
		if (tmp->next->value == numb)
		{
			delEl = true;
		}
	}
	if (!delEl)
	{
		printf("Element not found\n");
	}
	else
	{
		ListElement *delValue = tmp->next;
		tmp->next = tmp->next->next;
		delete(delValue);
	}
}


void PList::printList()
{
	ListElement *tmp = this->first->next;
	while (tmp != nullptr)
	{
		std::cout<<tmp->value<<" ";
		tmp = tmp->next;
	}
	std::cout<<"\n";
}

void PList::deleteList()
{
	ListElement *tmp = this->first;
	ListElement *delValue = tmp;
	while (tmp)
	{
		delValue = tmp;
		tmp = tmp->next;
		delete(delValue);
	}
}
