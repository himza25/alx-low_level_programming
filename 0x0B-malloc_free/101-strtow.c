#include "main.h"
#include <stdlib.h>

/**
 * count_words - Helper function to count the number of words in a string
 * @str: The string to count words in
 *
 * Return: The number of words in the string
 */
static unsigned int count_words(char *str)
{
	unsigned int count = 0, i = 0;

	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split
 *
 * Return: If str == NULL, str == "", or the function fails - NULL.
 *         Otherwise - a pointer to the array of words.
 */
char **strtow(char *str)
{
	char **words, *token;
	unsigned int count, i = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	count = count_words(str);
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	token = strtok(str, " ");
	while (token != NULL)
	{
		words[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (words[i] == NULL)
		{
			free(words);
			return (NULL);
		}
		words[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	words[i] = NULL;

	return (words);
}
