/*
 Anton Gulikov
*/

#include <stdio.h>
#include <string.h>

int main(){
	printf("Enter the number and I will write you a minimal anagram of the number\n");

	const int ds = 10;
	const int maxn = 100000;

	char *number = new char[maxn];
	scanf("%s",number);

	int *countDigit = new int[ds];
	for (int i = 0; i < ds; i++)
		countDigit[i] = 0;

	for (int i = 0; i < strlen(number); i++)
		countDigit[number[i] - '0']++;

	for (int i = 1; i < ds; i++)
		if (countDigit[i] > 0){
			printf("%d", i);
			countDigit[i]--;
			break;
		}

	for (int i = 0; i < ds; i++){
		for ( ; countDigit[i] > 0; countDigit[i]--)
			printf("%d", i);
	}

	delete[] number;
	delete[] countDigit;

	return 0;
}
