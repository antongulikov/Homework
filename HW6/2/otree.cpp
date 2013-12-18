#include "otree.h"
#include <stdio.h>
#include <string.h>

namespace scorpion{

	Tree *createTree(){
		Tree *newTree = new Tree;
		newTree->root = nullptr;
		return newTree;
	}

	TreeNode * createNewTreeNode(char ch, int val){
		TreeNode *newNode = new TreeNode;
		newNode->operation = ch;
		newNode->value = val;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return newNode;
	}

	
	void print(TreeNode *currentNode){
		if (currentNode == nullptr)
			return;
		printf(" ( ");
		print(currentNode->left);
		if (currentNode->operation == '!')
			printf("%d ", currentNode->value);
		else
			printf("%c ", currentNode->operation);
		print(currentNode->right);
		printf(" ) ");
	}

	void printTree(Tree *tree){
		print(tree->root);
	}

	int findLen(char *s){
		int res = strlen(s);
		while (res > 0 && s[res - 1] != ')')
			res--;
		return res;
	}

	void shiftUp(int &pos, int pos2, char *s){
		while (pos  < pos2 && s[pos] == ' ')
			pos++;
	}

	void shiftDown(int &pos, int pos2, char *s){
			while (pos >= pos2 && s[pos] == ' ')
				pos--;
	}

	bool isOperation(char ch){
		return (ch == '-' || ch == '+' || ch == '*' || ch == '/');
	}


	int close(int pos, char *s){
		int depth = 0;
		int n = findLen(s);
		for (int i = pos; i < n; i++){
			if (s[i] == '(')
				depth++;
			if (s[i] == ')')
				depth--;
			if (depth == 0)
				return i;
		}
		return n;
	}

	TreeNode *parse(char *s, int left, int right){
		if (left > right)
			return nullptr;
		if (left == right && s[left] == ' ')
			return nullptr;
		shiftUp(left, right, s);
		shiftDown(right, left, s);
		TreeNode *newNode = createNewTreeNode('!', 0);
		if (s[left] == '('){
			left++;
			right--;
		}
		shiftUp(left, right, s);
		if (isOperation(s[left])){
			newNode->operation = s[left];
			left++;
		} else {
			int val = 0;
			while ('0' <= s[left] && s[left] <= '9'){
				val = val * 10 + (s[left] - '0');
				left++;
			}
			newNode->value = val;
		}
		if (left <= right){
			shiftUp(left, right, s);

			if (s[left] == '('){
				newNode->left = parse(s, left, close(left, s));
				newNode->right = parse(s, close(left, s) + 1, right);
			}

			else{
				int currentPos = left;
				while (s[currentPos] != ' ')
					currentPos++;
				newNode->left = parse(s, left, currentPos);
				newNode->right = parse(s, currentPos, right);
			}
		}

		return newNode;
	}

	void parseString(char *s, Tree *tree){
		tree->root = parse(s, 0, findLen(s) - 1);
	}

	double calcOnTree(TreeNode *currentPos){
		if (currentPos->operation == '!')
			return 0.0 + currentPos->value;
		double x1 = calcOnTree(currentPos->left);
		double x2 = calcOnTree(currentPos->right);
		char operation = currentPos->operation;
		if (operation == '+')
			return x1 + x2;
		if (operation == '-')
			return x1 - x2;
		if (operation == '*')
			return x1 * x2;
		return x1 / x2;
	}

	double calc(Tree *tree){
		return calcOnTree(tree->root); 
	}

	void deleteNode(TreeNode *node){
		if (node == nullptr){
			delete node;
			return;
		}
		deleteNode(node->left);
		deleteNode(node->right);
		delete node;
	}

	void deleteTree(Tree *tree){
		deleteNode(tree->root);
	}

}


