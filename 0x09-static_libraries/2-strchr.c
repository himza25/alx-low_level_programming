#include "main.h"

/**
 * _strchr - locates a character in a string.
 * @s: string to be scanned.
 * @c: character to be searched in s.
 *
 * Return: pointer to the first occurrence of the character c in the string s,
 * or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			return (s);
		}
	} while (*s++);

	return (0);
}
