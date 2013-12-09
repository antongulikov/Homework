/*
 Anton Gulikov
*/
#include <stdio.h>

int main(){
	int x = 0;
	printf("Enter the value of the variable\nx= ");
	scanf("%d", &x);
	int x2 = x * x;
	int ans = (x2 + 1) * (x2 + x);
	printf("The value of x^4+x^3+x^2+x, when x=%d is %d\n", x, ans);
	return 0;
}	
