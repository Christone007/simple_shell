#include "shell.h"

/**
 * _strcat - Concatenate two strings
 * @dest: String to concatenate to
 * @src: String to be added
 * Return: Concatenate string
 */
char *_strcat(char *dest, char *src)
{
	int i, j, len;

	len = _strlen(dest);
	for (i = len, j = 0; src[j]; i++, j++)
	{
		dest[i] = src[j];

	}
	return (dest);
}
