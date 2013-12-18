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

using namespace std;

const int maxn = 100000;
bool fail[8] = { false, true, false, true, false, true, true, false};

enum state{
	sstart,
	sabs,
	snum,
	spoint,
	sreal,
	sexp,
	sexpabs,
	sdouble
};


bool isDigit(char ch){
	return ('0' <= ch && ch <= '9');
}

int nextPosition(int currentPosition, char currentSymbol){

	switch (currentPosition){

		case sstart : {
			if (currentSymbol == '+' || currentSymbol == '-')
				return sabs;
			if (isDigit(currentSymbol))
				return snum;
			return -1;

		}

		case sabs : {
			if (isDigit(currentSymbol))
				return snum;
			return -1;
		}

		case snum : {
			if (isDigit(currentSymbol))
				return snum;
			if (currentSymbol == 'E')
				return sexp;
			if (currentSymbol == '.')
				return spoint;
			return -1;
		}

		case spoint : {
			if (isDigit(currentSymbol))
				return sreal;
			return -1;
		}

		case sreal : {
			if (isDigit(currentSymbol))
				return sreal;
			if (currentSymbol == 'E')
				return sexp;
			return -1;						
		}

		case sexp : {
			if (currentSymbol == '+' || currentSymbol == '-')
				return sexpabs;
			if (isDigit(currentSymbol))
				return sdouble;
			return -1;
		}		
		case sexpabs : {
			if (isDigit(currentSymbol))
				return sdouble;
			return -1;
		}

		case sdouble : {
			if (isDigit(currentSymbol))
				return sdouble;
			return -1;			
		}
	} 
}

int main(){

	printf("Enter the number...\n");
	char *parseString = new char[maxn];
	memset(parseString, '\0', maxn);

	fgets(parseString, maxn, stdin);

	int currentPosition = 0;

	foru(i,strlen(parseString)){

		if (parseString[i] == '\n' || parseString[i] == '\0')
			break;
		if (parseString[i] == 'e')
			parseString[i] = 'E';

		currentPosition = nextPosition(currentPosition, parseString[i]);
		if (currentPosition == -1) 
			break;
	}

	delete[] parseString;

	if (currentPosition == -1 || fail[currentPosition])
		cout << "Wrong";
	else
		cout << "Accepted";
	return 0;
}