#include "htree.h"
#include <cstdio>

using namespace std;

namespace scorpion{

	
	TreeElement *createTreeElement(bool finish, int symbol, int count){
		TreeElement *newElement = new TreeElement;
		newElement->finish = finish;
		newElement->symbol = symbol;
		newElement->count = count;
		newElement->left = nullptr;
		newElement->right = nullptr;
		return newElement;
	}

	TreeElement *merge(TreeElement *first, TreeElement *second){
		TreeElement *newRoot = createTreeElement(false, 32, first->count + second->count);
		newRoot->left = first;
		newRoot->right = second;
		return newRoot;
	}


	void printTree(TreeElement *currentElement){
		if (currentElement == nullptr){
			printf("(null)");
			return;
		}
		printf("(%c", currentElement->symbol);
		printTree(currentElement->left);
		printTree(currentElement->right);
		printf(")");
	}

	void deleteTree(TreeElement *currentElement){
		if (currentElement == nullptr)
				return;
		deleteTree(currentElement->left);
		deleteTree(currentElement->right);
		delete currentElement;
	}	

}