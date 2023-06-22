#include <stdio.h>
#include <math.h>

/**
 * main - entry point
 * Return: always 0 (success)
 */
int main(void)
{
	long num = 612852475143;
	int i;

	for (i = 2; i <= sqrt(num); i++)
	{
		if (num % i)
			continue;
		num /= i;
		i--;
	}
	printf("%li\n", num);
	return (0);
}
