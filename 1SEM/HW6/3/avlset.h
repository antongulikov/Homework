#ifndef AVLSET_H
#define AVLSET_H
#pragma once

namespace scorpion {

	struct TreeNode{
		int value;
		int height;
		TreeNode *left;
		TreeNode *right;
	};

	struct Tree{
		TreeNode *root;
	};

	Tree *createTree();
	void insert(int x, Tree *tree);
	void remove(int x, Tree *tree);
	void printInIncreasingOrder(Tree *tree);
	void printInDecreasingOrder(Tree *tree);
	void printDebugerOrder(Tree *tree);
	bool find(int x, Tree *tree);
	void deleteTree(Tree *tree);
}

#endif // AVLSET_H
