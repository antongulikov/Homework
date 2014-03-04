
#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include <linstack.h>
#include <arraystack.h>
#include <string.h>

namespace scorpion{

	bool nums(char ch){
		return (ch >= '0' && ch <= '9');
	}

	bool signs(char ch){
		return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
	}

	bool brackets(char ch){
		return (ch == '(' || ch == ')');
	}

	int priority(char ch){
		if (ch == '+' || ch == '-')
			return 1;
		return 2;
	}

	bool bad(char ch){
		return (!signs(ch) && !nums(ch) && !brackets(ch));
	}

	char *toPolish(char *message){

		const int maxn = 100500;
		char *polish = new char[maxn];
		int lenPolish = 0;
		int lenMessage = strlen(message);
		while (lenMessage > 0 && bad(message[lenMessage - 1]))
			lenMessage--;
		Stack<char> *charStack = new LinStack<char>;
		for (int i = 0; i < lenMessage; i++){
			if (nums(message[i])){
				polish[lenPolish++] = message[i];
			}
			else if (message[i] == '('){
				charStack->push('(');
			} else if (signs(message[i])) {
				while (!charStack->isEmpty() && signs(charStack->top()) && priority(message[i]) <= priority(charStack->top())){
					polish[lenPolish++] = charStack->pop();
				}
				charStack->push(message[i]);
			}
			else if (message[i] == ')'){
				while (charStack->top() != '('){
					polish[lenPolish++] = charStack->pop();
				}
				charStack->pop();
			}
		}

		while (!charStack->isEmpty()){
			polish[lenPolish++] = charStack->pop();
		}

		delete charStack;
		char *result = new char[lenPolish];
		memset (result, 0, lenPolish * sizeof(char));
		for (int i = 0; i < lenPolish; i++)
			result[i] = polish[i];

		delete[] polish;
		return result;

	}

	double calcResult(char *polish){

		Stack<double> *doubleStack = new ArrayStack<double>();

		int lenPolish = strlen(polish);

		for (int i = 0; i < lenPolish; i++){
			if (nums(polish[i])){
				doubleStack->push(double(polish[i] - '0'));
			} else{
				double value1 = doubleStack->pop();
				double value2 = doubleStack->pop();
				double value3 = 0;
				if (polish[i] == '+')
					value3 = value1 + value2;
				else if (polish[i] == '-')
					value3 = value2 -value1;
				else if (polish[i] == '*')
					value3 = value2 * value1;
				else{
					if (value1 == 0){
						printf("Don't divide by zero!!!\n");
						system("pause");
						delete doubleStack;
						exit(0);
					}
					value3 = value2 / value1;
				}
				doubleStack->push(value3);
			}
		}

		double result = doubleStack->pop();
		delete doubleStack;
		return result;
	}

}
