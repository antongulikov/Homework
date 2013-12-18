/*
 Anton Gulikov
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
const long long inf=1000*1000*1000*1000*1000*1000;
const long long base=1000*1000*1000+7;

using namespace std;

// Формат вывода. n-1 ребро, задающие одно из остовных деревьев.

int main(){


	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);


	int n = 0;
	int ma = 0;
	scanf("%d", &n);
	int **a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
			ma = max(ma, a[i][j]);
		}


	bool *mark = new bool[n];
	for (int i = 0; i < n; i++)
		mark[i] = false;
	int *cost = new int[n];
	for (int i = 0; i < n; i++)
		cost[i] = ma;
	int *parent = new int[n];
	for (int i = 0; i < n; i++)
		parent[i] = i;
	int *ans = new int[n];
	for (int i = 0; i < n; i++)
		ans[i] = i;


	for (int step = 0; step < n; step++){
		int mi = ma;
		int pos = -1;
		for (int i = 0; i < n; i++)
			if (!mark[i] && cost[i]<=mi){
				pos = i;
				mi = cost[i];
			}
		ans[pos] = parent[pos];
		mark[pos] = true;
		for (int i = 0; i < n; i++)
			if (cost[i] >= a[pos][i]){
				parent[i] = pos;
				cost[i] = a[pos][i];
			}
	}

	for (int i = 0; i < n; i++)
		if (ans[i] != i)
			printf("%d %d\n", i + 1, ans[i] + 1);

	delete[] ans;
	delete[] mark;
	delete[] cost;		
	delete[] parent;

	for (int i = 0; i < n; i++)
		delete[] a[i];

	delete[] a;
	return 0;
}