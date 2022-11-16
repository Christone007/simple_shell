#include "shell.h"

/**
 * count_character - Counts the number of occurence of a given character
 * in a string
 * @str: The string
 * @c: The character to count
 *
 * Return: Number of @c found in @str
 */
int count_character(char *str, char c)
{
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;

		i++;
	}

	return (count);
}


/**
 * build_str - builds a new string using characters between two points
 * in a string
 * @str: The Base string
 * @start_pt: The starting character
 * @end_pt: The last character
 *
 * Return: The new string;
 */
char *build_str(char *str, unsigned int start_pt, unsigned int end_pt)
{
	char *newstr;
	int i = 0, j;

	j = (end_pt - start_pt) + 2;

	newstr = malloc(sizeof(char) * j);

	while (start_pt <= end_pt)
	{
		newstr[i] = str[start_pt];
		i++;
		start_pt++;
	}

	newstr[i] = '\0';

	return (newstr);
}

/**
 * free_array - Free all the memory occupied by a NULL terminated array
 * @arr: The array to free
 *
 * Return: void
 */
void free_array(char **arr)
{
	unsigned int i = 0;

	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr[i]);
	free(arr);
	
	return;
}
