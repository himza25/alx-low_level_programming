#include "main.h"

/**
 * _isdigit - check if the string is a number
 * @s: string to check
 * Return: 1 if is a number otherwise 0
 */
int _isdigit(char *s)
{
	while (*s)
		if (*s < '0' || *s > '9')
			return (0);
	else
			s++;
	return (1);
}

/**
 * print_number - print the given number
 * @s: string to print
 * @len: length of the string to print
 * Return: void
 */
void print_number(char *s, int len)
{
	while (len--)
		_putchar(*s++ + '0');
	_putchar('\n');
}

/**
 * mul - multiplies two numbers
 * @s1: first number
 * @s2: second number
 * Return: pointer to a buffer that contains the result
 */
int *mul(char *s1, char *s2)
{
	int l1, l2, a, b, *res;

	for (l1 = 0; s1[l1]; l1++)
		s1[l1] -= '0';
	for (l2 = 0; s2[l2]; l2++)
		s2[l2] -= '0';
	res = malloc(l1 + l2);
	if (!res)
		exit(98);
	for (b = l2 - 1; b >= 0; b--)
		for (a = l1 - 1; a >= 0; a--)
			res[a + b + 1] += s2[b] * s1[a];
	for (a = l1 + l2 - 1; a > 0; a--)
	{
		res[a - 1] += res[a] / 10;
		res[a] %= 10;
	}
	return (res);
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, otherwise 98
 */
int main(int argc, char *argv[])
{
	int *res;
	int l1, l2;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		puts("Error");
		exit(98);
	}
	l1 = 0;
	while (argv[1][l1])
		l1++;
	l2 = 0;
	while (argv[2][l2])
		l2++;
	res = mul(argv[1], argv[2]);
	if (res[0] == 0)
		l1--;
	print_number(res + l1 + l2 - 1, l1 + l2);
	free(res);
	return (0);
}
