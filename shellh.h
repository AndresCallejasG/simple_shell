#ifndef HOLBERTON
#define HOLBERTON
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


typedef struct list_PATH
{
	char *str;
	struct list_PATH *next;
} list_t;

typedef struct built_in
{
	char *cmd;
	int (*f)(char **av);

} built_in_t;

/* Function that tokenize input line to an **array */
char **_split(char *line);

int _processing(char **args);

int _execve(char **av);

void handle_ctrl_c(int sign);

/* tools */
int _strlen(char *str);
char *_str_concat(char *s1, char *s2);
int _putchar(char c);
int _puts(char *str);

/* list tools */
list_t *add_node_end(list_t **head, const char *str);
list_t *_linkPATH(list_t **head);
void free_list(list_t *head);
size_t print_list(const list_t *h);

/* handle PATH */
char *_full_path(const list_t *h, char *cmd);
char *_find_path(char *cmd);
int _check_path(char *str);

/* built-ins */
int own_exit(char **av);
int _print_env(char **av);

#endif
