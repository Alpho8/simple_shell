#ifndef SHELL_H
#define SHELL_H
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
extern char **environ;
char **tokenize(char *line);
void execute(char **args);
#endif
