#include "shellh.h"
/**
 * _print_env - prints the environment
 *
 * Return: Always 0.
 */

int _print_env(char __attribute__((unused)) **av)
{
    unsigned int i;
    extern char **environ;

    i = 0;

    while (environ[i] != NULL)
    {
        _puts(environ[i]);
        _putchar('\n');
        i++;
    }
    return (1);
}

/**
 * ourexit - checks whether the input is the exit command
 * @av: buffer with the commands
 * Return: Exit status
 */
int own_exit(char **av)
{

    /* Exit without args */
	if (av[1] == NULL)
	{
		free(av[0]);
		free(av);
		exit(EXIT_SUCCESS);
	}

    return (-1);
    
}

