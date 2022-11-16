#include "shell.h"

/**
 * main - Entry point
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
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
			free(linebuffer);
			return (2);
		}


		/*Last element of linebuffer('\n) should be replaced with '\0'*/
		linebuffer[result - 1] = '\0';

		child_pid = fork();
		if (child_pid == -1)
		{
			perror(argv[0]);
			free(linebuffer);
			return (2);
		}

		if (child_pid == 0)
		{
			/*Split using the spaces as delimeter*/
			splitted_str = _strsplit(linebuffer, ' ');

			if (execve(splitted_str[0], argv, env) == -1)
			{
				perror(argv[0]);
				free(linebuffer);
				return (2);
			}
			free(splitted_str[0]);
			free(splitted_str);
		}
		else
		{
			wait(NULL);
		}
	}
	free(linebuffer);
	return (0);
}
