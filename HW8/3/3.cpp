/*
 Anton Gulikov
 Создать input.txt N M количество вершин, рёбер, потом M строк описывайте рёбра.
*/

#pragma comment(linker,"/STACK:300000000")
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

void dfs(int v, int *value, int *next, int *last, bool *used){
	used[v] = true;
	printf("%d ", v + 1);
	int tmp = last[v];
	while (tmp > 0){
		if (!used[value[tmp]])
			dfs(value[tmp], value, next, last, used);
		tmp = next[tmp];
	}
	return;
}

void init(int *a, int n){
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	int *value = new int[1 + m + m];
	int *last = new int[n];
	int *next = new int[1 + m + m];
	bool *used = new bool[n];
	init(value, m + m + 1);
	init(last, n);
	init(next, m + m + 1);
	for (int i = 0; i < n; i++)
		used[i] = false;
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
	int numCom = 0;
	for (int i = 0; i < n; i++)
		if (!used[i]){
			numCom++;
			printf("In the %d component : ", numCom);
			dfs(i, value, next, last, used);
			printf("\n");
		}
        delete[] next;
        delete[] value;
        delete[] last;
        delete[] used;
        return 0;
}