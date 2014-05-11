#include <iostream>
#include "pointlist.h"
#include "arrlist.h"

int main()
{
	/*PoinerList *list = new PoinerList;
	list->addValue(7);
	list->addValue(3);
	list->addValue(11);
	list->printList();
	list->deleteValue(3);
	list->printList();
	delete list;*/
	aList *list = new aList;
	list->addValue(12);
	list->addValue(2);
	list->addValue(8);
	list->printList();
	list->deleteValue(2);
	list->deleteValue(5);
	list->printList();
	delete list;
}