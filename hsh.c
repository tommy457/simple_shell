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
		if (*line != '\n')
		{
			line[nchars - 1] = '\0';
			argv = split_line(line, delim, nchars);
			if (argv == NULL)
			{
				break;
			}
			if (execmd(argv) == -1)
			{
				free_arr(argv);
			}
		}
	}
	return (0);
}
/**
 * free_arr - frees an array
 * @argv: array to be freed
 * Return: NA
 */

void free_arr(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}
