
/*
	Anton Gulikov
	Создайте текстовый файл input.txt
	Программа создаст output.txt, где будут записаны все слова из input.txt , но над каждым совом будет произведена процедура unique,которая не учитывет регистр.

*/



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

const int maxn = 141195;
const int sizeAl = 26;

bool letter(char s){
	return (('a' <= s && s <= 'z') || ('A' <= s && s <= 'Z'));
}

void printAnswer(char *s, int n){
	if (n == 0) 
		return;
	bool *have = new bool[sizeAl];
	for (int i = 0; i < sizeAl; i++)
		have[i] = false;
	for (int i = 0; i < n; i++){
		if ('a' <= s[i] && s[i] <= 'z'){
			if (!have[s[i] - 'a'])
				printf("%c", s[i]);
			have[s[i] - 'a'] = true;
		} else {
			if (!have[s[i] - 'A'])
				printf("%c", s[i]);
			have[s[i] - 'A'] = true;
		}
	}
	delete[] have;
	printf("\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char *message = new char[maxn];

	while (cin >> message){
		int n = strlen(message);
		char *tmpMessage = new char[maxn];
		int sizeTmpMessage = 0;
		for (int i = 0; i < n; i++){
			if (!letter(message[i])){
				printAnswer(tmpMessage, sizeTmpMessage);
				sizeTmpMessage = 0;
			} else {
				tmpMessage[sizeTmpMessage++] = message[i];
			}
		}
		if (sizeTmpMessage != 0){
			printAnswer(tmpMessage, sizeTmpMessage);
			sizeTmpMessage = 0;
		}
		delete[] tmpMessage;
	}
	delete[] message;
	return 0;
}

