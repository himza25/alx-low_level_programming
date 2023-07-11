#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenate two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the concatenated string; NULL if failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i, j, length1 = 0, length2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[length1])
		length1++;
	while (s2[length2])
		length2++;

	concat = malloc(sizeof(char) * (length1 + length2 + 1));
	if (concat == NULL)
		return (NULL);

	for (i = 0; i < length1; i++)
		concat[i] = s1[i];
	for (j = 0; j < length2; j++, i++)
		concat[i] = s2[j];

	concat[i] = '\0';

	return (concat);
}
