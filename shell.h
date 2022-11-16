#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * struct dir_node - Struct for node of directories
 * @d_name: Name of directory
 * @next: Next directory
 * Description: A linked list of directories
 */
typedef struct directory_node
{
	char *d_name;
	struct directory_node *next;
} dir_node;

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

/**
 * launch - Launches the shell prompt
 * @argv: Arguments from main function
 * @env: Environment list
 * Return: Integers as success or error codes
 */
int launch(char **argv, char **env);

/**
 * command_check - Check for the existence of a command
 * @pathname: Path to the directory
 * @command: Command to check
 * Return: 1 if command exist, 0 if it cannot be found
 */
int command_check(char *pathname, char *command);

/**
 * launch - Launches the shell prompt
 * @argv: Arguments from main function
 * @env: Environment list
 * Return: Integers as success or error codes
 */
int launch(char **argv, char **env);

#endif
