#include "listtree.h"
#include "htree.h"

namespace scorpion{

	
	ListElement *createListElement(TreeElement *key){
		ListElement *newElement = new ListElement;
		newElement->key = key;
		newElement->next = nullptr;
		return newElement;
	}

	List *createList(){
		List *newList = new List;
		newList->header = createListElement(createTreeElement(false, 0, 0));
		return newList;
	}


	void deleteListElement(ListElement *currentElement){
		ListElement *deleteElement = currentElement->next;
		if (deleteElement == nullptr){
			currentElement->next = nullptr;
			return;
		} else{
			currentElement->next = deleteElement->next;
	//		deleteTree(deleteElement->key);			
		}
		delete deleteElement;
	}

	void deleteList(List *myList){
		while (myList->header->next != nullptr)
			deleteListElement(myList->header);
		delete myList->header;
		delete myList;
	}

	ListElement *lessThanThis(ListElement *currentElement, int count){
		while (currentElement->next != nullptr && currentElement->next->key->count < count)
			currentElement = currentElement->next;
		return currentElement;
	}

	void add(List *myList, TreeElement *key){
		ListElement *currentElement = lessThanThis(myList->header, key->count);
		ListElement *newElement = createListElement(key);
		newElement->next = currentElement->next;
		currentElement->next = newElement;
	}

	TreeElement *pop(List *myList){
		TreeElement *result = myList->header->next->key;
		deleteListElement(myList->header);
		return result;
	}

}