#include "main.h"
#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2,
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	unsigned long num1 = 0, num2 = 1, sum;

	for (count = 0; count < 50; count++)
	{
		sum = num1 + num2;
		num1 = num2;
		num2 = sum;

		printf("%lu", sum);

		if (count == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}
