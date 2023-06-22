#include "main.h"

/**
 * print_square - Prints a square using the character #.
 * @size: The size of the square.
 */
void print_square(int size)
{
	int width, height;

	if (size > 0)
	{
		for (height = 0; height < size; height++)
		{
			for (width = 0; width < size; width++)
				_putchar('#');
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
