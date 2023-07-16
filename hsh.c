#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 or -1
 */

int main(void)
{
	char *line = NULL, *line_cpy = NULL, *token, *delim = " \n";
	char **argv;
	size_t n = 0;
	int ncom = 0, i;
	ssize_t nchars;
	pid_t pid;
	int status;

	while (1)
	{

		printf("$ ");

		nchars = getline(&line, &n, stdin);
		if (nchars == -1)
		{
			free(line);
			perror("hsh: (getline)\n");
			exit(-1);
		}
		line_cpy = malloc(sizeof(char) * nchars);

		if (line_cpy == NULL)
		{
			free(line);
			perror("hsh: (malloc line_cpy)\n");
			exit(-1);
		}

		strcpy(line_cpy, line);

		token = strtok(line, delim);
		while (token != NULL)
		{
			ncom++;
			token = strtok(NULL, delim);
		}
		ncom++;

		argv = malloc(sizeof(char *) * ncom);
		if (argv == NULL)
		{
			free(line_cpy);
			free(line);
			perror("hsh: (malloc line_cpy)\n");
			exit(-1);
		}

		token = strtok(line_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("hsh: (fork)\n");
			exit(-1);
		}
		if (pid == 0)
			execmd(argv);
		else
		{
			wait(&status);
		}
	}
	free(line_cpy);
	free(line);
	return (0);
}
