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
#include <string.h>
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
const int maxn = 100000;
const long long P = 37;

using namespace std;


int main(){
	printf("Enter the Text\n");
	char *T = new char[maxn];
	fgets(T, maxn, stdin);
	printf("Enter the Sample\n");
	char *S = new char[maxn];
	fgets(S, maxn, stdin);
	int lengthS = strlen(S) - 1;
	int lengthT = strlen(T) - 1;

	long long cP = 1;
	long long hashS = 0;

	for (int i = 0; i < lengthS; i++){
		hashS = (hashS * P + S[i]) % base;
		if (i > 0)
			cP = (cP * P) % base;
	}

	if (lengthT < lengthS){
		printf("answer is 0");
	} else {
		int ans = 0;
		long long tmpH = 0;
		for (int i = 0; i < lengthS; i++)
			tmpH = (tmpH * P + T[i]) % base;
		for (int i = lengthS; i < lengthT; i++){
			if (tmpH == hashS)
				ans++;
			tmpH -= cP * T[i - lengthS];
			tmpH = (tmpH + base * base) % base;
			tmpH = (tmpH * P + T[i]) % base;
		}
		if (tmpH == hashS)
			ans++;
		printf("Answer is %d", ans);
	}

	delete[] T;
	delete[] S;
	return 0;
}
