#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

int is_digit(char *s);
void errors(void);
int *multiplication_logic(char *s1, char *s2, int len1, int len2);
void print_product(int *result, int len);

/**
 * is_digit - checks if a string contains a non-digit char
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiplication_logic - performs the actual multiplication logic
 * @s1: first number as a string
 * @s2: second number as a string
 * @len1: length of first number
 * @len2: length of second number
 *
 * Return: pointer to an array with the result
 */
int *multiplication_logic(char *s1, char *s2, int len1, int len2)
{
	int len, i, carry, digit1, digit2, *result;

	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		exit(98);
	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = s1[len1] - '0';
		carry = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			digit2 = s2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
	return (result);
}

/**
 * print_product - prints the product of the multiplication
 * @result: result of the multiplication
 * @len: length of the result
 */
void print_product(int *result, int len)
{
	int i, a = 0;

	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int *result, len1, len2;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		errors();
	s1 = argv[1];
	s2 = argv[2];
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	result = multiplication_logic(s1, s2, len1, len2);
	print_product(result, len1 + len2 + 1);
	free(result);
	return (0);
}
