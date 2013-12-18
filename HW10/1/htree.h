#pragma once

namespace scorpion{

	struct TreeElement{
		bool finish;
		int symbol;
		int count;
		TreeElement *left;
		TreeElement *right;
	};

		
	TreeElement *merge(TreeElement *first, TreeElement *second);
	TreeElement *createTreeElement(bool finish, int symbol, int count);
	void printTree(TreeElement *currentElement);
	void deleteTree(TreeElement *currentElement);
}