#ifndef _HEAD_
#define _HEAD_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

void execmd(char **commands);
char **split_line(char *arr, char *delim, ssize_t nchars);
char *find_path(char *name);
int _strcmp(char *s1, char *s2);
char *is_exe(char *command);

#endif
