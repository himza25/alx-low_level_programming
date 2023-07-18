#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - duplicate a string with new memory space
 * @str: string to duplicate
 * Return: pointer to the newly created string.
 */
char *_strdup(char *str)
{
	int i, len = 0;
	char *s;

	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}

/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: NULL if fail
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *doggo;

	doggo = malloc(sizeof(dog_t));
	if (doggo == NULL)
		return (NULL);

	doggo->name = _strdup(name);
	if (doggo->name == NULL)
	{
		free(doggo);
		return (NULL);
	}

	doggo->age = age;

	doggo->owner = _strdup(owner);
	if (doggo->owner == NULL)
	{
		free(doggo->name);
		free(doggo);
		return (NULL);
	}

	return (doggo);
}
