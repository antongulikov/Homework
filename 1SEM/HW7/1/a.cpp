/*
 Anton Gulikov
 Заносим в input.txt в формате. 1 строка Количество вершин количество рёбер. Следующие строки описыают рёбра графа.
 Ответ в output.txt
*/
#pragma comment(linker,"/STACK:300000000")
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <math.h>
#include <string>
#include <stdlib.h>

#define gcd(a,b) __gcd((a),(b))
#define sqr(a) ((a)*(a))
#define odd(a) ((a)&1)
#define foru(i,n) for (int i=0;i<(n);i++)
#define ford(i,n) for (int i=(n)-1;i>=0;i--)
#define forab(i,l,r) for (int i=(l);i<=(r);i++)
#define forabd(i,r,l) for (int i=(r);i>=(l);i--)
#define fillchar(a,b) memset((a),(b),sizeof((a)))
#define pb push_back
#define F first
#define S second
#define all(x) x.begin,x.end
#define pw2(x) (1ull<<(x))
#define mp make_pair

const long double eps=1e-20;
const long double pi=acos(-1.0);
const long long inf=1000*1000*1000*1ll*1000*1000*1000;
const long long base=1000*1000*1000+7;

using namespace std;

void intit(int *a, int n){
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

void dfs(int currentVertex, int *used, int *next, int *last, int *value, int color){

	if (used[currentVertex] != 0)
		return;
	used[currentVertex] = color;

	int tmp = last[currentVertex];
	while (tmp > 0){
		dfs(value[tmp], used, next, last, value, color);
		tmp = next[tmp];
	}

	return;
}

int main(){
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int numberOfStudents = 0;
	int numberOfRelationships = 0;
	scanf("%d %d", &numberOfStudents, &numberOfRelationships);

	int *next = new int[numberOfRelationships << 2 ];
	intit(next, numberOfRelationships << 2);

	int *last = new int[numberOfStudents << 2];
	intit(last, numberOfStudents << 2);

	int *value = new int[numberOfRelationships << 2];
	intit(value, numberOfRelationships << 2);

	int numberOfEdges = 0;

	for (int i = 1; i <= numberOfRelationships; i++){

		int first = 0;
		int second = 0;
		scanf("%d %d", &first, &second);

		numberOfEdges++;
		next[numberOfEdges] = last[first];
		last[first] = numberOfEdges;
		value[numberOfEdges] = second;

		numberOfEdges++;
		next[numberOfEdges] = last[second];
		last[second] = numberOfEdges;
		value[numberOfEdges] = first;

	}

	int *used = new int[numberOfStudents << 2];
	intit(used, numberOfStudents << 2);

	dfs(1, used, next, last, value, 1);
	dfs(2, used, next, last, value, 2);
	dfs(3, used, next, last, value, 3);

	for (int i = 1; i <= numberOfStudents; i++){
		if (used[i] == 0)
			printf("Student %d didn't pass an exam\n", i);
		else 
			printf("Student %d passed an exam and had a %d variant\n", i, used[i]); 
	}

	delete[] used;
	delete[] value;
	delete[] next;
	delete[] last; 

	return 0;
}