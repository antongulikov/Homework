#include "htree.h"
#include <algorithm>
#include <cstdio>
#include <string.h>

using namespace scorpion;
using namespace std;

const int maxn = 100000;

int findNext(int pos, char *parseString){
	bool fl = false;
	int balance = 0;
	for (int i = pos; 1 > 0; i++){
		if (parseString[i] == '(' || parseString[i] == ')'){
			fl = true;		
			if (parseString[i] == '(')
				balance++;
			else 
				balance--;
		}
		if (fl && balance == 0)
			return i;
	}
}

TreeElement *buildTree(int start, int finish, char *parseString){
	if (parseString[start + 2] == 'u'){
		return nullptr;
	}
	char symbol = parseString[start + 1];
	start++;
	while (parseString[start] != '(')
		start++;
	int end = findNext(start, parseString);
	TreeElement *left = buildTree(start, end, parseString);
	TreeElement *right = buildTree(end + 1, finish - 1, parseString);
	if (left == nullptr && right == nullptr){
		return createTreeElement(true, symbol, 1);
	}
	return merge(left, right);
}

int main(){
	freopen("output.txt", "r", stdin);
	freopen("decode.txt", "w", stdout);
	char *treeString = new char[maxn];
	memset(treeString, '\0', maxn);
	char *parseMessage = new char[maxn];
	memset(parseMessage, '\0', maxn);

	fgets(treeString, maxn, stdin);
	fgets(parseMessage, maxn, stdin);

	int n = strlen(treeString) - 1;

	while (n >=0 && treeString[n] != ')')
		n--;

	TreeElement *root = buildTree(0, n, treeString);
	TreeElement *currentElement = root;

	//printTree(root);
	int i = 1;
	while (i < strlen(parseMessage)){
		if (parseMessage[i] != '0' && parseMessage[i] != '1')
			break;
		if (parseMessage[i] == '0')
			currentElement = currentElement->left;
		else currentElement = currentElement->right;
		if (currentElement->finish){
			printf("%c", currentElement->symbol);
			i++;
			currentElement = root;
		}
		i++;
	}
	
	deleteTree(root);
	delete[] parseMessage;
	delete[] treeString;

}