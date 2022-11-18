#include "shell.h"
#include <stdio.h>

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argumets from the terminal
 * @env: Environment list
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	int ret_val;

	if (argc != 1)
	{
		_puts("Usage: ");
		_puts(argv[0]);
		_putchar('\n');
		return (1);
	}

	while (EOF)
	{
		ret_val = launch(argv, env);
		if (ret_val == 10)
			return (0);
		if (ret_val)
			return (ret_val);
	}
	return (0);
}
