#include "main.h"

/**
 * _strncat - Concatenates two strings up to n chars of src
 * @dest: The destination string. The source string will be appended to it.
 * @src: The source string that will be appended to the destination string.
 * @n: The number of characters to be appended from source.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0' && j < n; j++)
		dest[i + j] = src[j];
	if (j < n)
		dest[i + j] = '\0';

	return (dest);
}
