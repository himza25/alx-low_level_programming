#include "main.h"

/**
 * print_number - Prints a number.
 *
 * @num: The number to be printed.
 */
void print_number(int num)
{
	if (num >= 100)
	{
		_putchar((num / 100) + '0');
		_putchar(((num / 10) % 10) + '0');
		_putchar((num % 10) + '0');
	}
	else if (num >= 10)
	{
		_putchar((num / 10) + '0');
		_putchar((num % 10) + '0');
	}
	else
	{
		_putchar(num + '0');
	}
}

/**
 * print_commas_and_spaces - Prints commas and spaces.
 *
 * @num: The number to be printed.
 */
void print_commas_and_spaces(int num)
{
	_putchar(',');
	_putchar(' ');

	if (num <= 9)
	{
		_putchar(' ');
		_putchar(' ');
	}
	else if (num <= 99)
	{
		_putchar(' ');
	}
}

/**
 * print_times_table - Prints the n times table.
 *
 * @n: The number for which the times table is to be printed.
 */
void print_times_table(int n)
{
	int i, j, k;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				k = i * j;

				if (j != 0)
				{
					print_commas_and_spaces(k);
				}

				print_number(k);
			}
			_putchar('\n');
		}
	}
}
