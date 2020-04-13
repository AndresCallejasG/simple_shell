#include "shellh.h"
/**
 * _execve - exec commands
 *
 * @av: args
 * Return: 0
 */
int _execve(char **av)
{
    int status;
    pid_t child_pid;
    char *cmd_path;

    cmd_path = av[0];

    if (_check_path(av[0]) == 0)
    {
        /* printf("basic not found"); */
        cmd_path = _find_path(av[0]);
        /*still not found case*/
        if (cmd_path == NULL)
        {
            perror("Error: cmd not found");
            free(cmd_path);
            return(-1);
        }
    }
    /* printf("path is %s\n", cmd_path); */
        
    child_pid = fork();

    if (child_pid == 0)
    {
        if (execve(cmd_path, av, NULL) == -1)
        {
            perror("Error");
        }
    }
    else
    {
        wait(&status);
        /* printf("wait %d finished\n", i); */
    }
    free(cmd_path);
    return (0);
}

/**
 * _check_path - checks path
 *
 * @str: args
 * 
 * Return: full_path
 */
int _check_path(char *str)
{
    struct stat st;

    if (stat(str, &st) == 0)
        return (1);
    return (0);
}
/**
 * _find_path - find full path
 *
 * @str: args
 * 
 * Return: full_path
 */
char *_find_path(char *cmd)
{
    list_t **head;
    char *path;

	head = malloc(sizeof(list_t *));
	*head = NULL;
	
	_linkPATH(head);
    path = _full_path(*head, cmd);

	/* print_list(*head); */
	free_list(*head);
	free(head);
    return (path);
}
/**
 * print_list - prints all the elements of a list_t list.
 *
 * @h: List
 *
 * Return: number of elements
 */
char *_full_path(const list_t *h, char *cmd)
{
	const list_t *current;
    char *concat;

	if (h)
	{
		current = h;
        while (current)
		{
            concat = _str_concat(current->str, cmd);
            /* printf("concat %s\n", concat); */

			if (_check_path(concat))
            {
                printf("found\n");
				return (concat);
            }
			else
				free(concat);
			current = current->next;
		}
        printf("not found\n");
	}
	return (NULL);
}