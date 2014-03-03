/*
 Anton Gulikov
 В input.txt пишите ваш текст. В output.txt, по идее, должны выводится только комментарии типа '//'
*/
#pragma comment(linker,"/STACK:300000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
 	freopen ("input.txt", "r", stdin);
 	freopen ("output.txt", "w", stdout);

 	int maxn = 277;

 	char *currentRaw = new char[maxn];

 	bool fl1 = false;
 	bool fl2 = false;

 	while ( gets(currentRaw) ) {
 		int n = strlen(currentRaw);
 		int i = 0;
 		while (i < n) {
 			if (currentRaw[i] == '"') {
 				fl2 = !fl2;                                   
 				i++;
 				continue;                                   
 			}
 			if (currentRaw[i] == '*' && i + 1 < n && currentRaw[i + 1] == '/' && fl1) {
 				fl1 = false;
 				fl2 = false;
 				i += 2;
 				continue;
 			}
 			if (currentRaw[i] == '/' && i + 1 < n && currentRaw[i + 1] == '*' && !fl1 && !fl2) {
 				fl1 = true;
 				i += 2;
 				continue;
 			}
 			if (currentRaw[i] == '/' && i + 1 < n && currentRaw[i + 1] == '/' && !fl1 && !fl2) {
 				for (int j = i + 2; j < n; j++)
 					printf("%c", currentRaw[j]);
 				printf("\n");
 				i += n+n;
 			}
 			i++;
 		} 		
 	}
 	delete[] currentRaw;
 	return 0;
}

