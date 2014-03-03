#include "double.h"
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace scorpion;

const int maxn = 100000;

/*
	E  -> TE'
	E' -> (+|-)TE' | e
	T  -> FT'
	T' -> (*|/)FT' | e
	F  -> (E) | id


	E - Expression
	T - Temporary
	F - Finish
	' - Upgrade
*/

bool correctExpression(int &currentPosition, int lengthString, char *parseString);
bool correctExpressionUpgrade(int &currentPosition, int lengthString, char *parseString);
bool correctFinish(int &currentPosition, int lengthString, char *parseString);
bool correctTemporaryExpression(int &currentPosition, int lengthString, char *parseString);
bool correctTemporaryExpressionUpgrade(int &currentPosition, int lengthString, char *parseString);

bool correctExpression(int &currentPosition, int lengthString, char *parseString){

	if (currentPosition ==	lengthString)
		return true;

	if (currentPosition > lengthString)
		return false;


	return correctTemporaryExpression(currentPosition, lengthString, parseString) && correctExpressionUpgrade(currentPosition, lengthString, parseString);

}

bool correctExpressionUpgrade(int &currentPosition, int lengthString, char *parseString){

	if (currentPosition ==	lengthString)
		return true;

	if (currentPosition > lengthString)
		return false;

	if (parseString[currentPosition] == '+' || parseString[currentPosition] == '-'){
		currentPosition++;

		if (currentPosition > lengthString)
			return false;

		return correctTemporaryExpression(currentPosition, lengthString, parseString) && correctExpressionUpgrade(currentPosition, lengthString, parseString);
	}

	return true;

}

bool correctFinish(int &currentPosition, int lengthString, char *parseString){
	if (currentPosition ==	lengthString)
		return true;

	if (currentPosition > lengthString)
		return false;

	if (parseString[currentPosition] == '('){

		bool fl = correctExpression(++currentPosition, lengthString, parseString);

		if (currentPosition > lengthString)
			return false;		

		if (fl && parseString[currentPosition] == ')'){
			currentPosition++;
			return true;
		}

		return false;
	}
	int tmp = currentPosition;

	if (isDouble(parseString, currentPosition, lengthString))
		return true;

	currentPosition = tmp;

	return false;
}

bool correctTemporaryExpression(int &currentPosition, int lengthString, char *parseString){

	if (currentPosition ==	lengthString)
		return true;

	if (currentPosition > lengthString)
		return false;

	return correctFinish(currentPosition, lengthString, parseString) && correctTemporaryExpressionUpgrade(currentPosition, lengthString, parseString);
}

bool correctTemporaryExpressionUpgrade(int &currentPosition, int lengthString, char *parseString){

	if (currentPosition ==	lengthString)
		return true;

	if (currentPosition > lengthString)
		return false;

	if (parseString[currentPosition] == '*' || parseString[currentPosition] == '/'){
		currentPosition++;

		if (currentPosition > lengthString)
			return false;

		return correctFinish(currentPosition, lengthString, parseString) && correctTemporaryExpressionUpgrade(currentPosition, lengthString, parseString);
	}

	return true;
}



int main(){

	char *parseString = new char[maxn];
	memset(parseString, '\0', maxn);

	//fgets(parseString, maxn, stdin);
	cout << "Enter Expression\n";
	cin >> parseString;

	int currentPosition = 0;

	int lengthString = strlen(parseString);

	//while (lengthString > 0 && (parseString[lengthString] == '\n' || parseString[lengthString] == '\0'))
		//lengthString--;
	//lengthString++

	if (correctExpression(currentPosition, lengthString, parseString) && currentPosition == lengthString)
		cout << "Accepted!";
	else
		cout << "Wrong!";

	delete[] parseString;
}
