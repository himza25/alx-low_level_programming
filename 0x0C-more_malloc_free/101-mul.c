#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Error - print error and exit with status of 98
 */
void error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiply two numbers
 * @argc: number of arguments passed
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	long num1, num2, mul;

	if (argc != 3)
	{
		error();
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	if (num1 == 0 || num2 == 0)
	{
		error();
	}

	mul = num1 * num2;
	printf("%ld\n", mul);
	return (0);
}
