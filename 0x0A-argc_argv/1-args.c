#include <stdio.h>

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	/* To avoid compiler warning of unused variable */
	(void)argv;

	/* Since the first argument is always the program name, 
	the number of arguments passed into the program will be argc - 1 */
	printf("%d\n", argc - 1);

	return (0);
}
