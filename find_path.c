#include "main.h"

/**
 * find_path - checks for environment variable name
 * @name: name of the variable to be found
 *
 * Return: returns the value of the variable
 */

char *find_path(char *name)
{
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		if (_strcmp(environ[x], name) == 0)
		{
			break;
		}
		else if (environ[x + 1] == NULL)
			perror("find path");
	}

	return (environ[x]);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: returns to diff or -1
 */

int _strcmp(char *s1, char *s2)
{
	int diff, index;

	diff = index = 0;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	while (s1[index] != '\0' && s2[index] != '\0')
	{
		diff = s1[index] - s2[index];

		if (diff != 0)
			break;

		index++;
	}

	return (diff);
}
