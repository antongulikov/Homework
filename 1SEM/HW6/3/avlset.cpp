#include "avlset.h"
#include <stdio.h>


namespace scorpion {

	Tree *createTree(){
		Tree *newTree = new Tree;
		newTree->root = nullptr;
		return newTree;
	}

	TreeNode *createTreeNode(int value){
		TreeNode *newNode = new TreeNode;
		newNode->height = 1;
		newNode->value = value;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return newNode;
	}

	int height(TreeNode *node){
		if (node == nullptr)
			return 0;
		else return node->height;
	}

	int balanceFactor(TreeNode *node){
		return height(node->right) - height(node->left);
	}

	void updateHeight(TreeNode *node){
		int heightLeft = height(node->left);
		int heightRight = height(node->right);
		node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
	}

	TreeNode *findPosition(int x, TreeNode *currentPosition){
		if (currentPosition == nullptr)
			return currentPosition;
		if (currentPosition->value == x)
			return currentPosition;
		if (currentPosition->value > x)
			return findPosition(x, currentPosition->left);
		else
			return findPosition(x, currentPosition->right);
	}

	TreeNode *leftRotate(TreeNode *currentNode){
		TreeNode *newNode = currentNode->right;
		currentNode->right = newNode->left;
		newNode->left = currentNode;
		updateHeight(currentNode);
		updateHeight(newNode);
		return newNode;
	}

	TreeNode *rightRotate(TreeNode *currentNode){
		TreeNode *newNode = currentNode->left;
		currentNode->left = newNode->right;
		newNode->right = currentNode;
		updateHeight(currentNode);
		updateHeight(newNode);
		return newNode;
	}

	TreeNode *makeBalance(TreeNode *currentPosition){
		updateHeight(currentPosition);
		int bf = balanceFactor(currentPosition);
		if (-2 < bf && bf < 2)
			return currentPosition;
		if (bf == 2){
			if (balanceFactor(currentPosition->right) < 0)
				currentPosition->right = rightRotate(currentPosition->right);
			return leftRotate(currentPosition);
		} else{
			if (balanceFactor(currentPosition->left) > 0)
				currentPosition->left = leftRotate(currentPosition->left);
			return rightRotate(currentPosition);
		}
	}


	TreeNode *insertValue(int x, TreeNode *currentPosition){
		if (currentPosition == nullptr)
			return createTreeNode(x);
		if (currentPosition->value == x)
			return currentPosition;
		if (currentPosition->value > x)
			currentPosition->left = insertValue(x, currentPosition->left);
		else
			currentPosition->right = insertValue(x, currentPosition->right);
		return makeBalance(currentPosition);
	}

	void insert(int x, Tree *tree){
		tree->root = insertValue(x,tree->root);
	}

	TreeNode *findMinElement(TreeNode *currentPosition){
		if (currentPosition == nullptr)
			return nullptr;
		if (currentPosition->left == nullptr)
			return currentPosition;
		else return findMinElement(currentPosition->left);
	}
	
	TreeNode *removeMinElement(TreeNode *currentElement){
		if (currentElement == nullptr)
			return nullptr;
		if (currentElement->left == nullptr)
			return currentElement->right;
		currentElement->left = removeMinElement(currentElement->left);
		return makeBalance(currentElement);
	}
	
	
	TreeNode *removeElement(int x, TreeNode *currentElement){
		if (currentElement == nullptr)
			return nullptr;
		if (currentElement->value > x)
			currentElement->left = removeElement(x, currentElement->left);
		else if (currentElement->value < x)
			currentElement->right = removeElement(x, currentElement->right);
		else{
			TreeNode *leftPosition = currentElement->left;
			TreeNode *rightPosition = currentElement->right;
			delete currentElement;
			if (rightPosition == nullptr)			
				return leftPosition;
			TreeNode *minElement = findMinElement(rightPosition);
			minElement->right = removeMinElement(rightPosition);
			minElement->left = leftPosition;
			return makeBalance(minElement);
		}
		return makeBalance(currentElement);
	}

	void remove(int x, Tree *tree){
		tree->root = removeElement(x, tree->root);
	}

	void printInc(TreeNode *currentPosition){
		if (currentPosition == nullptr)
			return;
		printInc(currentPosition->left);
		printf("%d ", currentPosition->value);
		printInc(currentPosition->right);
	}

	void printDec(TreeNode *currentPosition){
		if (currentPosition == nullptr)
			return;
		printDec(currentPosition->right);
		printf("%d ", currentPosition->value);
		printDec(currentPosition->left);
	}

	void printInIncreasingOrder(Tree *tree){
		printInc(tree->root);
		printf("\n");
	}

	void printInDecreasingOrder(Tree *tree){
		printDec(tree->root);
		printf("\n");
	}

	void printDebug(TreeNode *currentPostion){
		if (currentPostion == nullptr){
			printf(" null");
			return;
		}
		printf(" (%d", currentPostion->value);
		printDebug(currentPostion->left);
		printDebug(currentPostion->right);
		printf(")");
	}

	void printDebugerOrder(Tree *tree){
		printDebug(tree->root);
		printf("\n");
	}

	bool find(int x, Tree *tree){
		return findPosition(x, tree->root) != nullptr;
	}

	void deleteNode(TreeNode *currentNode){
		if (currentNode == nullptr){
			delete currentNode;
			return;
		}
		deleteNode(currentNode->left);
		deleteNode(currentNode->right);
		delete currentNode;
	}

	void deleteTree(Tree *tree){
		deleteNode(tree->root);
		delete tree;
	}
}
