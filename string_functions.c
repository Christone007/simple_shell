#include "shell.h"

/**
 * _strlen - Gets length of a string
 * @s: String
 * Return: length of string
 */
unsigned int _strlen(char *s)
{
	unsigned int i;


	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - Compare two string to check for equality
 * @s1: First string
 * @s2: Second String
 * Return: Difference between their characters
 */
int _strcmp(char *s1, char *s2)
{
	int len1, len2;
	unsigned int i;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (len1 != len2)
	{
		return (len1 - len2);
	}

	i = 0;
	while (s1[i])
	{
		if (s1[i] - s2[i] != 0)
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (0);
}

/**
 * _strcpy - Copies the characters in src into dest
 * @dest: Pointer to the string to be copied to
 * @src: Pointer to the source to be copied from
 * Return: the copied string
 */
char *_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strncpy - Copies the characters in src into dest
 * @dest: Pointer to the string to be copied to
 * @src: Pointer to the source to be copied from
 * @n: the number of bytes to copy
 * Return: the copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}


/**
 * _strsplit - Splits a string into an array using the specified delimeter
 * @str: The string to split
 * @delim: The delimeter to split by
 *
 * Description: Splits a string into words at points marked by
 * a delimeter(@delim). The malloc'ed space containing the NULL terminated
 * array of strings must be freed by the calling function
 *
 * Return: NULL terminated Array of strings
 */
char **_strsplit(char *str, char delim)
{
	char **string_arr, *newstr;
	unsigned int delim_count = 0, i = 0, k, start_pt, end_pt;

	delim_count = count_character(str, delim);

	string_arr = malloc(sizeof(char *) * (delim_count + 2));

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delim)
		{
			start_pt = i;
			while (str[i + 1] != delim)
			{
				if (str[i + 1] == '\0')
					break;
				i++;
			}
			end_pt = i;

			/*Create string using start and end_pts*/
			newstr = build_str(str, start_pt, end_pt);

			/*Add the string to the array*/
			string_arr[k] = newstr;
			k++;
		}
		i++;
	}

	string_arr[k] = NULL;

	return (string_arr);
}
