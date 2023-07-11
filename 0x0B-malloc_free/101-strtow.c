#include "main.h"
#include <stdlib.h>

/**
 * wordlen - Finds the length of a word
 * @str: The word as a string
 *
 * Return: The length of the word
 */
static int wordlen(char *str)
{
	int len = 0;

	while (*(str + len) && *(str + len) != ' ')
		len++;
	return (len);
}

/**
 * wordcount - Counts the number of words in a string
 * @str: The string to be searched
 *
 * Return: The number of words in the string
 */
static int wordcount(char *str)
{
	int count = 0, inword = 0;

	do {
		switch (*str)
		{
			case ' ':
			case '\t':
			case '\n':
			case '\0':
				if (inword)
				{
					inword = 0;
					count++;
				}
				break;
			default:
				inword = 1;
		}
	} while (*str++);
	return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The string to be splitted
 *
 * Return: If str == NULL or str == "", or the function fails - NULL.
 *         Otherwise - a pointer to the array of words.
 */
char **strtow(char *str)
{
	char **words = NULL;
	int wc = 0, wi = 0, li = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	wc = wordcount(str);
	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (*str)
	{
		if (*str >= '!')
		{
			if (words[wi] == NULL)
			{
				words[wi] = malloc((wordlen(str) + 1) * sizeof(char));
				if (words[wi] == NULL)
				{
					while (--wi >= 0)
						free(words[wi]);
					free(words);
					return (NULL);
				}
			}
			words[wi][li] = *str;
			words[wi][++li] = '\0';
		}
		else if (words[wi] != NULL && li > 0)
		{
			wi++;
			li = 0;
		}
		str++;
	}
	words[wi] = NULL;
	return (words);
}
