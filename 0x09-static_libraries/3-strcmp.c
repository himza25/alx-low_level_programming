#include "main.h"

/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: Positive difference if s1 > s2, negative if s1 < s2, 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

