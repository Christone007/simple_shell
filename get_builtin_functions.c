#include "shell.h"
#include <string.h>

/**
 * get_builtin_func - Get the builtin function with the specified name
 * @name: Name of builtin function
 * Return: The builtin function
 */
builtin_func get_builtin_func(char *name)
{
	int i;
	builtin_f b_func[] = {
		{"exit", exit_f}
	};

	for (i = 0; i < 1; i++)
	{
		if (strcmp(b_func[i].function_name, name) == 0)
		{
			return (b_func[i].function_call);
		}
	}

	return (NULL);
}
