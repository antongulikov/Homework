/*
 Anton Gulikov
*/
#include <stdio.h>

void KMP(char message[], int lenM, int p[])
{
	for (int i = 1; i < lenM; ++i)
	{
		int j = p[i - 1];
		while ((j > 0) && (message[i] != message[j]))
			j = p[j - 1];
		if (message[i] == message[j])
			++j;
	       	p[i] = j;
	}
}

int main()
{
	printf("Enter the s and s1 in the differents raws\n");
	char t[111111];
	char s[111111];

	scanf("%s", t);
	scanf("%s", s);

	int lenT = strlen(t);
	int lenS = strlen(s);

	char message[lenT + lenS + 3];

	int lenM = 0;

	for (int i = 0; i < lenS; ++i)
	{
		message[lenM] = s[i];
		++lenM;		
	}
	message[lenM] = '~';
	for (int i = 0; i < lenT; ++i)
	{
		message[lenM] = t[i];
		++lenM;
	}

	int p[lenM];
	for (int i = 0; i <lenM; ++i)
		p[i] = 0;

	KMP (message, lenM, p);

	int ans = 0;

	for (int i = 0; i < lenM; ++i)
	{
		if (p[i] == lenS)
			ans++;
	}

	printf("%d", ans);

	return 0;
}
