#include "main.h"

/**
 * times_table - Prints the 9 times table, starting with 0
 *
 * Return: Nothing
 */

void times_table(void)
{
	int i, j, result;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			result = i * j;
			if (j != 0)
			{
			_putchar(',');
			_putchar(' ');
				if (result < 10)
					_putchar(' ');
				else
					_putchar((result / 10) + '0');
			}
			_putchar((result % 10) + '0');
		}
		_putchar('\n');
	}
}
