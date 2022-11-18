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
	size_t n;
	ssize_t result;
	char *linebuffer, *command, **splitted_str;
	char pathname[] = "/bin/", prompt[] = "#cisfun$ ";
	builtin_func builtin_function;

	n = 0;
	linebuffer = NULL;
	if (isatty(0))
		_puts(prompt);
	result = getline(&linebuffer, &n, stdin);
	if (result == -1)
	{
		free(linebuffer);
		return (10);
	}
	linebuffer[result - 1] = '\0';
	splitted_str = _strsplit(linebuffer, ' ');
	command = splitted_str[0];
	if (path_to_cmd(command) != NULL)
		command = path_to_cmd(command);
	builtin_function = get_builtin_func(command);
	if (builtin_function)
	{
		free_array(splitted_str);
		free(linebuffer);
		builtin_function(env);
	}
	if (command_check(pathname, command) == 1)
	{
		execute_command(pathname, command, &linebuffer,
				&splitted_str, argv, env);
		free_array(splitted_str);
	}
	else
	{
		printf("%s: command not found\n", argv[0]);
	}
	free(linebuffer);
	return (0);
}

/**
 * path_to_cmd - Check if a command is a path
 * @command: Command to check
 * Return: new command
 */
char *path_to_cmd(char *command)
{
	if (*command == '/')
	{
		command++;
		while (*command != '/')
			command++;
		command++;
		return (command);
	}
	return (NULL);
}

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
		    char **argv, char **env)
{
	pid_t child_pid;
	char *path;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(argv[0]);
		free(*linebuffer);
		return (2);
	}

	if (child_pid == 0)
	{
		path = _strcat(pathname, command);
		if (execve(path, *splitted_str, env) == -1)
		{
			perror(argv[0]);
			free_array(*splitted_str);
			free(*linebuffer);
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
