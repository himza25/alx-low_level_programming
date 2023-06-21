#include "main.h"
#include <stdio.h>

/**
 * Function that prints all natural numbers from n to 98, followed by a new line
 *
 * Print all natural numbers from n to 98
 */

void print_to_98(int n)
{
	if (n > 98)
	{
		for (; n > 98; n--)
			printf("%d, ", n);
	}
	else
	{
		for (; n < 98; n++)
			printf("%d, ", n);
	}
	printf("98\n");
}
