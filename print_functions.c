#include "shell.h"

/**
 * _putchar - Print a character
 * @c: Character
 * Return: Number of bytes printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints an array of characters
 * @s: Array of characters
 * Return: Number of bytes printed
 */
unsigned int _puts(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}
