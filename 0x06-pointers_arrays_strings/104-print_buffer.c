#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer
 * @size: size
 */
void print_buffer(char *b, int size)
{
	int offset, byte_index, chunk_size;

	offset = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (offset < size)
	{
		chunk_size = size - offset < 10 ? size - offset : 10;
		printf("%08x: ", offset);
		for (byte_index = 0; byte_index < 10; byte_index++)
		{
			if (byte_index < chunk_size)
				printf("%02x", *(b + offset + byte_index));
			else
				printf("  ");
			if (byte_index % 2)
			{
				printf(" ");
			}
		}
		for (byte_index = 0; byte_index < chunk_size; byte_index++)
		{
			int c = *(b + offset + byte_index);

			if (c < 32 || c > 132)
			{
				c = '.';
			}
			printf("%c", c);
		}
		printf("\n");
		offset += 10;
	}
}
