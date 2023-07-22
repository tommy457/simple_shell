#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 or -1
 */

int main(void)
{
	char *line = NULL, *delim = " \n";
	char **argv = NULL;
	size_t n = 0;
	ssize_t nchars;
	int int_mode = 1;

	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "~$ ", 3);
		}
		nchars = getline(&line, &n, stdin);
		if (nchars == -1)
		{
			printf("Eroor1\n");
			exit(EXIT_FAILURE);
		}
		if (*line == '\n')
		{
			continue;
		}
		argv = split_line(line, delim, nchars);
		execmd(argv);
	}
	free(argv);
	free(line);
	return (0);
}
