/*
 Anton Gulikov
*/

#include <stdio.h>
#include <string.h>

int main(){
	printf("Give me two strings and i told you, Is it right that s1 is a anagram of the s2\n");

	const int maxn = 100000;
	const int alphabet = 256;

	char *s1 = new char[maxn];
	char *s2 = new char[maxn];	
	fgets(s1, maxn, stdin);
	fgets(s2, maxn, stdin);
	int lengthS1 = strlen(s1);
	int lengthS2 = strlen(s2);
	bool answer = false;

	answer = lengthS1 == lengthS2;

	int *countChar = new int[alphabet];
	for (int i = 0; i < alphabet; i++){
		countChar[i] = 0;
	}

	if (answer){
		for (int i = 0; i < lengthS1; i++){
			countChar[s1[i]]++;
			countChar[s2[i]]--;
		}	
		for (int i = 0; i < alphabet; i++){
			if (countChar[i] != 0){
				answer = false;
				break;
			}
		}      
	}

	printf(answer ? "Yes" : "No");

	delete[] s1;
	delete[] s2;
	delete[] countChar;

	return 0;
}