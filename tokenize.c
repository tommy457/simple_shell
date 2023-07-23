#include "main.h"
/**
 * split_line - splites a string to multiple strings depending on the delim
 * @line: string to be splite
 * @delim: delimiter to splite with
 * @nchars: number of characrters in the string line
 *
 * Return: splite the line or null
 */

char **split_line(char *line, char *delim, ssize_t nchars)
{
	char **argv;
	char *token, *line_cpy;
	int ncom = 0, i;

	line_cpy = malloc(sizeof(char) * nchars + 1);
	strcpy(line_cpy, line);

	token = strtok(line, delim);
	while (token != NULL)
	{
		++ncom;
		token = strtok(NULL, delim);
	}

	argv = malloc(sizeof(char *) * (ncom + 1));
	if (argv == NULL)
	{
		free(line_cpy);
		perror("(malloc)");
		return (NULL);
	}

	token = strtok(line_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(line_cpy);
	return (argv);
}
