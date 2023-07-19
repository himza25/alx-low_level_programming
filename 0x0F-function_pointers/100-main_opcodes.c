#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 for incorrect number of arguments,
 *         2 for negative number of bytes.
 */
int main(int argc, char *argv[])
{
	int num_bytes, i;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	unsigned char *main_ptr = (unsigned char *)&main;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", main_ptr[i]);

		if (i < num_bytes - 1)
			printf(" ");
	}

	printf("\n");

	return (0);
}
