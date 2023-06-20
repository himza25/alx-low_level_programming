#include "main.h"

int print_last_digit(int n)
{
	int last = n % 10;

	if (last < 0)
		last = -last;
	
	_putchar('0' + last);
	return (last);
}
