#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include "scorpiondoublestack.h"
#include "scorpioncharstack.h"
#include <string.h>

namespace scorpion{

	bool nums(char ch){
		return (ch >= '0' && ch <= '9');
	}

	bool signs(char ch){
		return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
	}

	int priority(char ch){
		if (ch == '+' || ch == '-')
			return 1;
		return 2;
	}

	char *toPolish(char *message){

		const int maxn = 100500;
		char *polish = new char[maxn];
		int lenPolish = 0;
		int lenMessage = strlen(message);
		CharStack *charStack = createNewCharStack();
		for (int i = 0; i < lenMessage; i++){
			if (nums(message[i])){
				polish[lenPolish++] = message[i];
			}
			else if (message[i] == '('){
				pushCharElement(charStack,'(');
			} else if (signs(message[i])) {
				while (!isCharStackEmpty(charStack) && signs(topCharElement(charStack)) && priority(message[i]) <= priority(topCharElement(charStack))){
					polish[lenPolish++] = popCharElement(charStack);
				}
				pushCharElement(charStack, message[i]);
			}
			else if (message[i] == ')'){
				while (topCharElement(charStack) != '('){
					polish[lenPolish++] = popCharElement(charStack);
				}
				popCharElement(charStack);
			}
		}

		while (!isCharStackEmpty(charStack)){
			polish[lenPolish++] = popCharElement(charStack);
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

		DoubleStack *doubleStack = createNewDoubleStack();

		int lenPolish = strlen(polish);

		for (int i = 0; i < lenPolish; i++){
			if (nums(polish[i])){
				pushDoubleElement(doubleStack, double(polish[i] - '0'));
			} else{
				double value1 = popDoubleElement(doubleStack);
				double value2 = popDoubleElement(doubleStack);
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
				pushDoubleElement(doubleStack, value3);
			}
		}
		
		double result = popDoubleElement(doubleStack);
		delete doubleStack;
		return result;
 	}

}