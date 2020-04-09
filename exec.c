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

    child_pid = fork();

    if (child_pid == 0)
    {
        if (execve(av[0], av, NULL) == -1)
        {
            perror("Error");
        }
    }
    else
    {
        wait(&status);
        /* printf("wait %d finished\n", i); */
    }
    return (0);
}