/**
 * _strcat - Concatenates two strings
 * @dest: The destination string. The source string will be appended to it.
 * @src: The source string that will be appended to the destination string.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';

	return (dest);
}
