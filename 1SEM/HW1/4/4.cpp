/*
	Anton Gulikov
*/

#include <stdio.h>

int main()
{
	// Наслаждайтесь.
	const int dimension = 10;
	int lucky[3 * dimension] = { 0 };

	for (int firstDigit = 0; firstDigit < dimension; ++firstDigit)
		for (int secondDigit = 0; secondDigit < dimension; ++secondDigit)
			for (int thirdDigit = 0; thirdDigit < dimension; ++thirdDigit)
				++lucky[firstDigit + secondDigit + thirdDigit];

	int ans = 0;

	for (int sumDigits = 0; sumDigits < 3 * dimension; ++sumDigits)
		ans += lucky[sumDigits] * lucky[sumDigits];

	printf("The number of the lucky ticket is %d\n", ans);
	return 0;
}
