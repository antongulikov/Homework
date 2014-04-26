#pragma once
#include "node.h"
#include <string>
using namespace std;
/// class for tree
class Tree
{
public:
	Tree(const string &message);
	~Tree();
	/// print tree to screen
	void print();
	/// count the value of expression
	int count();
private:
	Node *root;
	Node *buildTree(const string &message, int &position);
};

