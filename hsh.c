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
	ssize_t nchars;
	int int_mode = 1, is_builtin;

	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
			write(STDOUT_FILENO, "~$ ", 3);
		signal(SIGINT, sigintHandler);
		nchars = _getline(&line);
		if (nchars == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (*line != '\n')
		{
			argv = split_line(line, delim, nchars);
			if (argv == NULL)
				break;
			is_builtin = check_builtin(argv);
			if (is_builtin == -1)
			{
				free_arr(argv);
				free(line);
				exit(EXIT_SUCCESS);
			}
			else if (is_builtin == 1)
			{
				if (execmd(argv) == -1)
					free_arr(argv);
			}
		}
		free(line);
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

/**
 * _getline - reads from stdin
 * @line: array to store the input
 *
 * Return: number od chars or -1
 */
int _getline(char **line)
{
	int i;

	*line = malloc(10240 * sizeof(char));
	i = read(STDIN_FILENO, *line, 10240);
	if (i == 0)
	{
		return (-1);
	}
	(*line)[i] = '\0';

	return (i);
}
/**
 * sigintHandler - handels signels
 * @sig_num: signel number
 *
 * Return: NA
 */

void sigintHandler(__attribute__((unused))int sig_num)
{
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "~$ ", 3);
}
