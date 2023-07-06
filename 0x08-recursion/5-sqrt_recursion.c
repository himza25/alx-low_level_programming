#include "main.h"

/**
 * helper - checks for square root of c
 * @i: integer
 * @c: integer
 * Return: square root or -1
 */
int helper(int i, int c)
{
	if (i * i == c)
		return (i);
	else if (i * i > c)
		return (-1);
	else
		return (helper(i + 1, c));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer
 * Return: result
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else
		return (helper(1, n));
}
