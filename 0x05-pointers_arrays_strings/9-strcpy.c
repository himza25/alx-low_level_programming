#include "main.h"

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: the pointer to the buffer where the source is copied
 * @src: the pointer to the source string
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *tmp = dest;

	while ((*dest++ = *src++))
		;

	return tmp;
}
