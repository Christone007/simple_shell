#include <stdio.h>
#include <string.h>
#include "shell.h"

/**
 * launch - Launches the shell prompt
 * @argv: Arguments from main function
 * @env: Environment list
 * Return: Integers as success or error codes
 */
int launch(char **argv, char **env)
{
	char *linebuffer;
	size_t n;
	ssize_t result;
	char prompt[] = "#cisfun$ ";
	char pathname[] = "/bin/";
	char **splitted_str;
	int i;

	n = 0;
	linebuffer = NULL;

	_puts(prompt);
	result = getline(&linebuffer, &n, stdin);
	if (result == -1)
	{
		perror(argv[0]);
		free(linebuffer);
		return (2);
	}

	linebuffer[result - 1] = '\0';
	splitted_str = _strsplit(linebuffer, ' ');

	i = command_check(pathname, splitted_str[0]);
	if (i == 1)
	{
		execute_command(pathname, linebuffer, splitted_str, argv, env);
	}
	else
	{
		_puts(argv[0]);
		_puts(": command not found");
		_putchar('\n');
	}
	free(linebuffer);
	return (0);
}

/**
 * execute_command - Fork and Execute
 * @pathname: Pathname
 * @linebuffer: Buffer for getline function
 * @splitted_str: Splitted strings from line buffer
 * @argv: Main arguments
 * @env: Enviroment list
 * Return: Integers
 */
int execute_command(char *pathname, char *linebuffer, char **splitted_str,
		    char **argv, char **env)
{
	pid_t child_pid;
	char *path;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(argv[0]);
		free(linebuffer);
		return (2);
	}

	if (child_pid == 0)
	{
		path = _strcat(pathname, splitted_str[0]);
		if (execve(path, splitted_str, env) == -1)
		{
			perror(argv[0]);
			free_array(splitted_str);
			free(linebuffer);
			return (2);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

/**
 * command_check - Check for the existence of a command
 * @pathname: Path to the directory
 * @command: Command to check
 * Return: 1 if command exist, 0 if it cannot be found
 */
int command_check(char *pathname, char *command)
{
	DIR *dir_stream;
	struct dirent *dir_entry;
	int isequal;

	dir_stream = opendir((const char *) pathname);
	if (dir_stream ==  NULL)
		return (0);

	dir_entry = readdir(dir_stream);
	if (dir_entry == NULL)
		return (0);

	while (dir_entry != NULL)
	{
		isequal = strcmp(command, dir_entry->d_name);
		if (isequal == 0)
		{
			closedir(dir_stream);
			return (1);
		}
		dir_entry = readdir(dir_stream);
	}
	closedir(dir_stream);
	return (0);
}
