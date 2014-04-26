#include "tree.h"
#include "node.h"
#include "plus.h"
#include "minus.h"
#include "divide.h"
#include "multiply.h"
#include "number.h"

Tree::Tree(const string &message)
{		
	int tmpPosition = 0;
	root = buildTree(message, tmpPosition);
}

Tree::~Tree()
{
	delete root;
}

void Tree::print()
{
	root->print();
}

int Tree::count()
{
	return root->count();
}


Node *Tree::buildTree(const string &message, int &position)
{	
	int n = message.size();
	Node *newNode = nullptr;
	while (position < n && (message[position] == ' ' || message[position] == ')'))
		position++;
	if (position >= n)
		return newNode;
	if (message[position] == '('){
		position++;
		switch (message[position]){
			case '+':
				newNode = new Plus();
				break;
			
			case '-':
				newNode = new Minus();
				break;
			
			case '*':
				newNode = new Multiply();
				break;
			
			case '/':
				newNode = new Divide();
				break;
			
		}		
		position++;
		newNode->setLeft(buildTree(message, position));
		newNode->setRight(buildTree(message, position));			
		return newNode;			
	}
	int value = 0;
	int sign = 1;
	if (message[position] == '-'){
		sign = -1;
		position++;		
	}
	while (message[position] >= '0' && message[position] <= '9'){
		value = value * 10 + (message[position] - '0');
		position++;
	}	
	position++;
	newNode = new Number(value * sign);
	return newNode;
}
