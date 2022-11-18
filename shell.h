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
 * struct builtin_s - Builtin function struct
 * @function_name: Name of builtin function
 * @function_call: Function to be called
 */
typedef struct builtin_s
{
	char *function_name;
	void (*function_call)(char **env);
} builtin_f;

typedef void (*builtin_func)(char **env);
/**
 * get_builting_func - Get the builtin function with the specified name
 * @name: Name of builtin function
 * Return: The builtin function
 */
builtin_func get_builtin_func(char *name);

/**
 * exit_f - Exit a process
 * @env: Environment list
 */
void exit_f(char **env);

/**
 * env_f - Prints all the environment list
 * @env: Environment list
 */
void env_f(char **env);

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
 * _strcat - Concatenate two strings
 * @dest: String to concatenate to
 * @src: String to be added
 * Return: Concatenate string
 */
char *_strcat(char *dest, char *src);

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
 * path_to_cmd - Check if a command is a path
 * @command: Command to check
 * Return: new command
 */
char *path_to_cmd(char *command);

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
 * execute_command - Fork and Execute
 * @pathname: Pathname
 * @command: Command to execute
 * @linebuffer: Buffer for getline function
 * @splitted_str: Splitted strings from line buffer
 * @argv: Main arguments
 * @env: Enviroment list
 * Return: Integers
 */
int execute_command(char *pathname, char *command,
		    char **linebuffer, char ***splitted_str,
		    char **argv, char **env);

#endif
