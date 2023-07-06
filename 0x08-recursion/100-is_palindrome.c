#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to get the length of.
 *
 * Return: The length of @s.
 */
int _strlen(char *s)
{
	if (*s)
		return (1 + _strlen(s + 1));
	else
		return (0);
}

/**
 * check - Checks if a string is a palindrome.
 * @s: The string to check.
 * @i: The index of the string to start the check from.
 * @len: The length of the string.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int check(char *s, int i, int len)
{
	if (i >= len / 2)
		return (1);
	else if (s[i] == s[len - i - 1])
		return (check(s, i + 1, len));
	else
		return (0);
}

/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The string to check.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int len = _strlen(s);

	if (!*s)
		return (1);
	else
		return (check(s, 0, len));
}
