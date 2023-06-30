#include "main.h"

/**
 * print_buffer - prints a buffer with a specific format
 * @b: pointer to the buffer
 * @size: the size of the buffer
 */
void print_buffer(char *b, int size)
{
	int i, j;

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);
		for (j = 0; j < 10; j++)
		{
			if (j % 2 == 0)
				printf(" ");
			if (i + j < size)
				printf("%02x", *(b + i + j));
			else
				printf("  ");
		}
		printf(" ");
		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
				putchar(isprint(*(b + i + j)) ? *(b + i + j) : '.');
		}
		putchar('\n');
	}
	if (size <= 0)
		putchar('\n');
}
