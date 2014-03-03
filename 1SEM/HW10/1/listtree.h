#include "htree.h"

namespace scorpion{

	struct ListElement{
		TreeElement *key;
		ListElement *next;
	};

	struct List{
		ListElement *header;
	};

	List *createList();
	ListElement *createListElement(TreeElement *key);
	void deleteList(List *myList);
	void add(List *myList, TreeElement *key);
	TreeElement *pop(List *myList);
}