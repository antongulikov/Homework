#include "calculator.h"
#include <linstack.h>
#include <arraystack.h>
#include <cstdio>
#include "string.h"

bool Calculator:: nums(char ch){
	return (ch >= '0' && ch <= '9');
}

bool Calculator:: signs(char ch){
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

bool Calculator:: brackets(char ch){
	return (ch == '(' || ch == ')');
}

int Calculator::  priority(char ch){
	if (ch == '+' || ch == '-')
		return 1;
	return 2;
}

bool Calculator:: bad(char ch){
	return (!signs(ch) && !nums(ch) && !brackets(ch));
}


// '!' - divided symbol

char* Calculator:: toPolish(const char *message){
	const int maxn = 100500;
	char *polish = new char[maxn];
	int lenPolish = 0;
	int lenMessage = strlen(message);
	while (lenMessage > 0 && bad(message[lenMessage - 1]))
		lenMessage--;
	Stack<char> *charStack = new LinStack<char>;
	if (message[0] == '-'){
		polish[lenPolish++] = '0';
		polish[lenPolish++] = '!';
	}
	for (int i = 0; i < lenMessage; i++){
		
		if (nums(message[i])){
			int startPosition = i;
			while (startPosition < lenMessage && nums(message[startPosition])){
				polish[lenPolish++] = message[startPosition];
				startPosition++;
			}
			polish[lenPolish++] = '!';
			i = startPosition - 1;
		}
		else if (message[i] == '('){
			charStack->push('(');
		} else if (signs(message[i])) {
			while (!charStack->isEmpty() && signs(charStack->top()) && priority(message[i]) <= priority(charStack->top())){
				polish[lenPolish++] = charStack->pop();
				polish[lenPolish++] = '!';
			}
			charStack->push(message[i]);
		}
		else if (message[i] == ')'){
			while (charStack->top() != '('){
				polish[lenPolish++] = charStack->pop();
				polish[lenPolish++] = '!';
			}
			charStack->pop();
		}
		
		
	}
	
	while (!charStack->isEmpty()){
		
		polish[lenPolish++] = charStack->pop();
		polish[lenPolish++] = '!';
	}
	
	delete charStack;
	
	char *result = new char[lenPolish];
	memset (result, 0, lenPolish * sizeof(char));
	
	for (int i = 0; i < lenPolish; i++){
		result[i] = polish[i];
	}
	delete[] polish;
	return result;
}

int Calculator:: calcResult(char *polish){
	Stack<int> *intStack = new ArrayStack<int>();
	int lenPolish = strlen(polish);
	while (lenPolish > 0 && polish[lenPolish - 1] != '!')
		lenPolish--;
	for (int i = 0; i < lenPolish; i++){
		if (polish[i] == '!')
			continue;
		if (nums(polish[i])){
			int ret = 0;
			int startPosition = i;
			while (startPosition < lenPolish && nums(polish[startPosition])){
				ret = ret * 10 + int(polish[startPosition++] - '0');				
			}
			intStack->push(ret);
			i = startPosition - 1;
		} else{
			if (intStack->size() < 2){
				delete intStack;
				return - (1 << 30);			
			}				
			int value1 = intStack->pop();
			int value2 = intStack->pop();
			int value3 = 0;
			if (polish[i] == '+')
				value3 = value1 + value2;
			else if (polish[i] == '-')
				value3 = value2 -value1;
			else if (polish[i] == '*')
				value3 = value2 * value1;
			else{
				if (value1 == 0){
					delete intStack;
					return -(1 << 30);					
				}
				value3 = value2 / value1;
			}
			intStack->push(value3);
		}
	}
	int result = intStack->pop();
	delete intStack;
	return result;
}

int Calculator:: calculate(const char *message){
	return calcResult(toPolish(message));
}
