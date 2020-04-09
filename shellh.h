#ifndef HOLBERTON
#define HOLBERTON
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function that tokenize input line to an **array */
char **_split(char *line);

int _processing(char **args);

int _execve(char **av);



#endif
