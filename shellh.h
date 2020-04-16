#ifndef HOLBERTON
#define HOLBERTON
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct list_PATH - singly linked list
 *
 * @str: string - (malloc'ed string)
 *
 * @next: points to the next node
 *
 */
typedef struct list_PATH
{
	char *str;
	struct list_PATH *next;
} list_t;

/**
 * struct built_in - built-ins list
 *
 * @cmd: command - (malloc'ed string)
 *
 * @f: especific funcion
 *
 */

typedef struct built_in
{
	char *cmd;
	int (*f)(char **av);

} built_in_t;

/* handle errors */
void print_error(int status, char **args, int count, char *shell_name);
void handle_ctrl_c(int sign);

/* handle comments # */
void clean_comments(char *line);

/* Main tools */
char **_split(char *line);
int _processing(char **args);
int _execve(char **av);

/* print tools */
int _putchar(char c);
int _puts(char *str);
void _print_number_err(int n);
int _puts_err(char *str);
int _putchar_err(char c);


/* tools */
void free_grid(char **grid);
int _atoi(char *s);

/* list tools */
list_t *add_node_end(list_t **head, char *str);
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

/* str tools */
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_str_concat(char *s1, char *s2);

#endif
