#include "main.h"
/**
 * execmd - exectute commands
 * @commands: array of commands
 *
 * Return: NA
 */

int execmd(char **commands)
{
	pid_t pid;
	char *command = NULL;
	int status;

	if (commands)
	{
		command = is_exe(commands[0]);

		if (command != NULL)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("hsh: (fork)\n");
				free(command);
				return (-1);
			}
			if (pid == 0)
			{
				if (execve(command, commands, environ) == -1)
				{
					perror("Error:");
					free(command);
					return (-1);
				}
			}
			else
				wait(&status);
			free(command);

		}
		else
		{
			perror("Command");
			return (-1);
		}
	}
	return (-1);
}
/**
 * is_exe - checks if a command is in PATH
 * @command: command to be cheked
 *
 * Return: full path of a command or NULL
 */

char *is_exe(char *command)
{
	char *path, *path_cpy, *path_tok, *file_path, *name = "PATH";
	int comm_length, dir_length;
	struct stat buffer;

	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	path = find_path(name);
	if (path)
	{
		path_cpy = strdup(path);
		comm_length = strlen(command);

		path_tok = strtok(path_cpy, ":");

		while (path_tok != NULL)
		{
			dir_length = strlen(path_tok);
			file_path = malloc(comm_length + dir_length + 2);
			strcpy(file_path, path_tok);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_tok = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		return (NULL);
	}
	return (NULL);
}

