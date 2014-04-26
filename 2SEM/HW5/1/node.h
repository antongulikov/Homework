#pragma once
#include "iostream"
using namespace std;
/// basic class for nodes
class Node
{
public:
	Node();
	~Node();
	/// count the value in node's subtree
	virtual int count() = 0;
	/// print node's subtree
	virtual void print() = 0;
	void setLeft(Node *value);
	void setRight(Node *value);
protected:
	Node *left;
	Node *right;
};

