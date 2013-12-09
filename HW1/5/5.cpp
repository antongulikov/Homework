/*
 Anton Gulikov
*/
#include <stdio.h>
#include <string.h>

int main()
{
	printf("Enter  the string of '(' and ')'\n");
	char s[11111];
	scanf("%s", s);

	int depth = 0;
	int n = strlen(s);

	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '(')
			depth++;
		if (s[i] == ')')
			depth--;
		if (depth < 0)
		{
			printf("%s is a bad string", s);
			return 0;
		}
	}

	if (depth == 0)
		printf("%s is a good string", s);
	else
		printf("%s is a bad string", s);

	return 0;
}