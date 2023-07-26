#ifndef _HEAD_
#define _HEAD_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/**
 * struct builtin_func  - ...
 * @command: ...
 * @f: ...
 */

typedef struct builtin_func
{
	char *command;
	int (*f)(char **argv);
} builtin_func;

void sigintHandler(__attribute__((unused))int sig_num);

int execmd(char **commands);
char **split_line(char *arr, char *delim, ssize_t nchars);
char *find_path(char *name);
int _strcmp(char *s1, char *s2);
char *is_exe(char *command);
void free_arr(char **argv);
int _getline(char **line);

int check_builtin(char **arr);

int exit_func(char **arr);
int env_func(char **arr);
int cd(char **args);

#endif

