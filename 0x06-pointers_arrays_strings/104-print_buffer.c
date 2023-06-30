#include "main.h"

/**
 * print_buffer - prints a buffer with a specific format.
 * @b: buffer.
 * @size: size of the buffer.
 */
void print_buffer(char *b, int size)
{
	int i, j;

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);
		for (j = 0; j < 10; j++)
		{
			if (j % 2 == 0 && j != 0)
				printf(" ");
			if (j + i < size)
				printf("%02x", *(b + i + j));
			else
				printf("  ");
		}
		printf(" ");
		for (j = 0; j < 10; j++)
		{
			if (j + i < size)
			{
				if (*(b + i + j) >= 31 && *(b + i + j) <= 126)
					printf("%c", *(b + i + j));
				else
					printf(".");
			}
		}
		printf("\n");
	}
	if (size <= 0)
		printf("\n");
}
