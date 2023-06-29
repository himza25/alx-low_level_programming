#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @s: string to encode
 *
 * Return: pointer to the encoded string
 */
char *rot13(char *s)
{
	int i, j;
	char normal[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; normal[j] != '\0'; j++)
		{
			if (s[i] == normal[j])
			{
				s[i] = rot[j];
				break;
			}
		}
	}

	return (s);
}
