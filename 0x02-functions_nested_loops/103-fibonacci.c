#include "main.h"

/**
 * main - finds and prints the sum of the even-valued terms in the
 * Fibonacci sequence whose values do not exceed 4,000,000.
 * Return: Always 0.
 */
int main(void)
{
	int i;
	unsigned long a = 1, b = 2, sum = 0, temp;

	for (i = 1; b <= 4000000; i++)
	{
		if (b % 2 == 0)
			sum += b;
		temp = a + b;
		a = b;
		b = temp;
	}

	print_numbers(sum);
	_putchar('\n');

	return (0);
}

/**
 * print_number - prints an integer char by char
 * @n: The integer to print
 *
 * Return: void
 */
void print_numbers(unsigned long n)
{
	if (n / 10)
	{
		print_numbers(n / 10);
	}
	_putchar((n % 10) + '0');
}
