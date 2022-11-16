#include "shell.h"

/**
 * _strcat - Concatenate two strings
 * @dest: String to concatenate to
 * @src: String to be added
 * Return: Concatenate string
 */
char *_strcat(char *dest, char *src)
{
	char *start;

	start = dest;
	while (*start != '\0')
	{
		start++;
	}

	while (*src != '\0')
	{
		*start = *src;
		src++;
		start++;
	}

	*start = '\0';
	return (dest);
}
