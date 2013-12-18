/*
 Anton Gulikov
 Как обычно создаём граф в input.txt получаем ответ в output.txt
*/
#pragma comment(linker,"/STACK:300000000")
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

const int inf = 1000000000;

void readEdges(int m, int **a){
	while (m--){
		int x = 0;
		int y = 0;
		int len = 0;
		scanf("%d %d %d", &x, &y, &len);
		x--;
		y--;
		a[x][y] = len;
		a[y][x] = len;
	}
}

void findMinPath(int **a, int *dist, int *prev, int *active, int cur, int n){
	bool end = true;
	dist[cur] = 0;
	do{
		active[cur] = 1;
		for (int i = 0; i < n; i++)
			if (dist[i] > dist[cur] + a[cur][i]){
				active[i] = 0;
				dist[i] = dist[cur] + a[cur][i];
				prev[i] = cur;				
			}
		end = true;
		int mine = inf;
		for (int i = 0; i < n; i++)
			if (active[i] == 0 && dist[i] < mine){
				end = false;
				mine = dist[i];
				cur = i;
			}		
	} while (!end);
}

void printWay(int vertex, int *prev, int n){
	int *way = new int[n];
	int sizeWay = 0;
	int tmp = vertex;
	while (tmp != -1){
		way[sizeWay++] = tmp;
		tmp = prev[tmp];
	}
	for (int j = sizeWay - 1; j >= 0; --j)
		printf("%d ", way[j] + 1);
	printf("\n");
	delete[] way;	
}

int main(){

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt" ,"w", stdout);
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);

	int **a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = inf;

	 readEdges(m, a);


	int *dist = new int [n];
	int *prev = new int [n];
	for (int i = 0; i < n; i++){
		prev[i] = -1;
		dist[i] = inf;
	} 

	int *active = new int[n];
	for (int i = 0; i < n; i++)
		active[i] = 0;

	findMinPath(a, dist, prev, active, 0, n);

	delete[] active;

	int *step = new int[n];
	for (int i = 0; i < n; i++)
		step[i] = i;


	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			if (dist[step[i]] > dist[step[j]])
				swap(step[i], step[j]);


	for (int i = 0; i < n; i++){
		int vertex = step[i];
		if (dist[vertex] == inf){
			printf("Hitler is loser! He can't to enter in %d city!\n", vertex + 1);
		} else{
			printf("On the %d day they entered in %d City with Distance %d\n", i, vertex + 1, dist[vertex]);
			printf("Way : ");
			printWay(vertex, prev, n);
		}
	}

	delete[] step;
	delete[] dist;
	delete[] prev;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}