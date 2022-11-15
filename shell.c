#include "shell.h"

/**
 * main - Entry point
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *linebuffer;
	size_t n;
	ssize_t result;
	pid_t child_pid;
	char shell_tag[] = "#cisfun$ ";
	char **splitted_str;

	if (argc != 1)
	{
		_puts("Usage: ");
		_puts(argv[0]);
		_putchar('\n');
		return (1);
	}

	n = 0;
	linebuffer = NULL;
	while (EOF)
	{
		_puts(shell_tag);
		result = getline(&linebuffer, &n, stdin);
		if (result == -1)
		{
			perror(argv[0]);
			return (2);
		}

		splitted_str = _strsplit(linebuffer, '\n');
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
			return (2);
		}

		if (child_pid == 0)
		{
			if (execve(splitted_str[0], splitted_str, NULL) == -1)
			{
				perror(argv[0]);
				return (2);
			}
		}
		else
		{
			wait(NULL);
		}
		free(splitted_str[0]);
		free(splitted_str);
	}
	free(linebuffer);
	return (0);
}
