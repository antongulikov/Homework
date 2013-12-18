/*
 Anton Gulikov
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>


using namespace std;

int main(){

	printf("Enter double x. You will give a  representation of x in normalized form.\n"); 


	double x = 0;
	cin >> x;
	unsigned char *pos = (unsigned char *) &x;
	int k = 7;
	int size = 0;
	int *a = new int[65];
	while (k >= 0) {
		int x = (1 << 7);
		while (x) {
			a[size++] = x & (pos[k]) ? 1 : 0;
			x >>= 1;
		}
		k--;
	}
	printf( a[0] ? "-" : "+");
	int st2 = 1;
	int exponent = 0;
	for (int i = 11; i >= 1; i--) {
		exponent += a[i] * st2;
		st2 += st2;
	}


	double mantissa = 1;	
	double std2 = 1;

	for (int i = 12; i <= 63; i++) {
		std2 /= (0.0 + 2);
		mantissa += std2 * a[i];
	}

	exponent = exponent - (1 << 10 ) + 1;
	cout.precision(4*exponent);
	cout<<mantissa;
	printf("*2^(%d)", exponent);

	delete[] a;
	return 0;
}

