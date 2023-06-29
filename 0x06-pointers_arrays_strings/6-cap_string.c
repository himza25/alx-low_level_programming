#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to be modified
 *
 * Return: a pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0;

	while (str[i])
	{
		/* Check if character is a word separator */
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ',' ||
		       str[i] == ';' || str[i] == '.' || str[i] == '!' || str[i] == '?' ||
		       str[i] == '"' || str[i] == '(' || str[i] == ')' || str[i] == '{' ||
		       str[i] == '}')
		{
			i++;

			/* If next character is lower case */
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - 'a' + 'A';
			}
		}

		i++;
	}

	return (str);
}
