#include "main.h"

/**
 * Function to print the last digit of a number
 *
 * Print last digit of the number
 */

int print_last_digit(int n)
{
	int last = n % 10;

	if (last < 0)
		last = -last;
	
	_putchar('0' + last);
	return (last);
}
