#include "main.h"
/**
 * execmd - exectute commands
 * @commands: array of commands
 *
 * Return: NA
 */

void execmd(char **commands)
{
	char *command = NULL;

	if (commands)
	{
		command = commands[0];

		execve(command, commands, NULL);
		perror("Error:");

	}
}
