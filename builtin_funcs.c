#include "main.h"
/**
 * exit_func - exit the program
 * @arr: array of arguments
 *
 * Return: -1
 */

int exit_func(__attribute__((unused))char **arr)
{
	return (-1);
}
/**
 * env_func - prints env variables
 * @arr: array of arguments
 *
 * Return: 0
 */

int env_func(char **arr)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_arr(arr);
	return (0);
}

/**
 * cd - changes dir
 * @args: array of arguments
 *
 * Return: 0 or 2
 */

int cd(char **args)
{
	static char *prev_dir, currpwd[1024], oldpwd[1024];

	if (_strcmp(args[1], "-") != 0)
	{
		getcwd(oldpwd, 1024);
		prev_dir = oldpwd;

		if (chdir(args[1]) != 0)
			perror("lsh");
		else
		{
			getcwd(currpwd, 1024);
			printf("%s\n", currpwd);
		}
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (prev_dir == NULL)
		{
			perror("sh: cd: OLDPWD not set");
			free_arr(args);
			return (2);
		}
		else if (chdir(prev_dir) != 0)
			perror("lsh");
		printf("%s\n", prev_dir);
	}
	free_arr(args);
	return (0);
}
