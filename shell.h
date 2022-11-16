#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _putchar - Print a character
 * @c: Character
 * Return: Number of bytes printed
 */
int _putchar(char c);

/**
 * _puts - Prints an array of characters
 * @s: Array of characters
 * Return: Number of bytes printed
 */
unsigned int _puts(char *s);

/**
 * _strlen - Gets length of a string
 * @s: String
 * Return: length of string
 */
unsigned int _strlen(char *s);

/**
 * _strcmp - Compare two string to check for equality
 * @s1: First string
 * @s2: Second String
 * Return: Difference between their characters
 */
int _strcmp(char *s1, char *s2);

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
char **_strsplit(char *str, char delim);

/**
 * count_character - Counts the number of occurence of a given character
 * in a string
 * @str: The string
 * @c: The character to count
 *
 * Return: Number of @c found in @str
 */
int count_character(char *str, char c);


/**
 * build_str - builds a new string using characters between two points
 * in a string
 * @str: The Base string
 * @start_pt: The starting character index
 * @end_pt: The last character index
 *
 * Return: The new string;
 */
char *build_str(char *str, unsigned int start_pt, unsigned int end_pt);


/**
 * free_array - Free all the memory occupied by a NULL terminated array
 * @arr: The array to free
 *
 * Return: void
 */
void free_array(char **arr);

#endif
