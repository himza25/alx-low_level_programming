#include <stdlib.h>
#include "main.h"

/**
 * word_counter - helper function to count the number of words in a string
 * @str_input: string to evaluate
 *
 * Return: number of words
 */
int word_counter(char *str_input)
{
	int new_word_flag, char_index, word_num;

	new_word_flag = 0;
	word_num = 0;

	for (char_index = 0; str_input[char_index] != '\0'; char_index++)
	{
		if (str_input[char_index] == ' ')
			new_word_flag = 0;
		else if (new_word_flag == 0)
		{
			new_word_flag = 1;
			word_num++;
		}
	}

	return (word_num);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **word_array, *tmp_word;
	int index, array_index = 0, str_length = 0, word_count, word_length = 0;
	int word_start = 0, word_end = 0;

	while (*(str + str_length))
		str_length++;
	word_count = word_counter(str);
	if (word_count == 0)
		return (NULL);

	word_array = (char **) malloc(sizeof(char *) * (word_count + 1));
	if (word_array == NULL)
		return (NULL);

	for (index = 0; index <= str_length; index++)
	{
		if (str[index] == ' ' || str[index] == '\0')
		{
			if (word_length)
			{
				word_end = index;
				tmp_word = (char *) malloc(sizeof(char) * (word_length + 1));
				if (tmp_word == NULL)
					return (NULL);
				while (word_start < word_end)
					*tmp_word++ = str[word_start++];
				*tmp_word = '\0';
				word_array[array_index] = tmp_word - word_length;
				array_index++;
				word_length = 0;
			}
		}
		else if (word_length++ == 0)
			word_start = index;
	}

	word_array[array_index] = NULL;

	return (word_array);
}
