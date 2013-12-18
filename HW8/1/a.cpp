/*
 Anton Gulikov
 Создаёте свой файл получаете ответ в answer.txt
*/
#pragma comment(linker,"/STACK:300000000")
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

void init(int *a, int n){
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

void dfs(int v, int *value, int *next, int *last, int *used, int color){
	used[v] = color;
	int tmp = last[v];
	while (tmp > 0){
		if (used[value[tmp]] == -1)
			dfs(value[tmp], value, next, last, used, color + 1);
		tmp = next[tmp];
	}
}

int main(){
	char *s = new char[20];
	int start = 0;
	cin >> s >> start;
	freopen (s , "r" , stdin);
	freopen ("answer.txt", "w", stdout);
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	if (n > 26){
		printf("I can't do it!!!");
		delete[] s;
		return 0;
	}
	start--;
	int *value = new int[1 + m + m];
	int *last = new int[n];
	int *next = new int[1 + m + m];
	int *used = new int[n];
	init(value, m + m + 1);
	init(last, n);
	init(next, m + m + 1);
	for (int i = 0; i < n; i++)
		used[i] = -1;
	int numEdges = 0;
	for (int i = 0; i < m; i++){
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		numEdges++;
		next[numEdges] = last[x];
		last[x] = numEdges;
		value[numEdges] = y;
		numEdges++;
		next[numEdges] = last[y];
		last[y] = numEdges;
		value[numEdges] = x;
	}

	dfs(start, value, next, last, used, 0);

	for (int i = 0; i < n; i++)
		printf("Let %d will be a %c\n", i + 1, 'a' + used[i]);

	delete[] s;
	delete[] value;
	delete[] next;
	delete[] last;
	delete[] used;
}