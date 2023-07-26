#include "main.h"

/**
 * check_builtin - checks if command is built in
 * @arr: array of arguments
 *
 * Return: 1
 */

int check_builtin(char **arr)
{
	int i;

	builtin_func builtin[] = {
		{"exit", exit_func},
		{"env", env_func},
		{"cd", cd},
		{NULL, NULL}
	};

	for (i = 0; builtin[i].command != NULL; i++)
	{
		if (_strcmp(arr[0], builtin[i].command) == 0)
		{
			return (builtin[i].f(arr));
		}
	}
	return (1);
}
