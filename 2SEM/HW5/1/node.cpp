#include "node.h"

Node::Node() : left(nullptr), right(nullptr)
{
}

Node::~Node()
{
	if (this){		
		delete left;
		delete right;		
	}
}

void Node::setLeft(Node *value)
{
	left = value;
}

void Node::setRight(Node *value)
{
	right = value;
}
