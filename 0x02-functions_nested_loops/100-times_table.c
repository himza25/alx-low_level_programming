#include "main.h"

void print_number(int number) 
{
	if (number >= 100) 
	{
		_putchar((number / 100) + '0');
		_putchar(((number / 10) % 10) + '0');
		_putchar((number % 10) + '0');
	}
	else if (number >= 10) 
	{
		_putchar((number / 10) + '0');
		_putchar((number % 10) + '0');
	}
	else 
	{
		_putchar(number + '0');
	}
}

void print_row(int i, int n) 
{
	for (int j = 0; j <= n; j++)
	{
		int k = i * j;

		if (j != 0)
		{
			_putchar(',');
			_putchar(' ');

			if (k <= 9)
			{
				_putchar(' ');
				_putchar(' ');
			}
			else if (k <= 99)
			{
				_putchar(' ');
			}
		}

		print_number(k);
	}
	_putchar('\n');
}

void print_times_table(int n)
{
	if (n >= 0 && n <= 15)
	{
		for (int i = 0; i <= n; i++)
		{
			print_row(i, n);
		}
	}
}
