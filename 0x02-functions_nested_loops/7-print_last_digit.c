#include "main.h"

/**
 * print_last_digit - Print the last digit of a number
 * @n: The number to be checked
 *
 * Return: The value of the last digit
 */
int print_last_digit(int n)
{
	int last = n % 10;

	if (last < 0)
		last = -last;
	_putchar('0' + last);
	return (last);
}
