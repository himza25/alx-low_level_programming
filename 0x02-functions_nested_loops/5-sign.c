#include "main.h"

/**
 * print_sign - Prints the sign of a number
 * @n: The number to be checked
 *
 * Return: 1 if the number is positive, -1 if it's negative, and 0 if it's zero
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
