#include "shell.h"

/**
 * exit_f - Exit a process
 * @env: Environment list
 */
void exit_f(char __attribute__((unused)) **env)
{
	exit(0);
}

/**
 * env_f - Prints all the environment list
 * @env: Environment list
 */
void env_f(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i])
	{
		_puts(env[i]);
		i++;
	}
}
