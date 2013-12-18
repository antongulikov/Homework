#ifndef OTREE_H
#define OTREE_H
#pragma once

namespace scorpion{

	struct TreeNode{
		char operation;
		int value;
		TreeNode *left;
		TreeNode *right;
	};

	struct Tree{
		TreeNode *root;
	};

	void printTree(Tree *tree);

	double calc(Tree *tree);

	TreeNode *createNewTreeNode(char ch, int val);

	Tree *createTree();

	void parseString(char *s, Tree *tree);

	void deleteTree(Tree *tree);

}

#endif // OTREE_H
