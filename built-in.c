#include "shellh.h"
/**
 * _print_env - prints the environment
 *
 * @av: buffer with the commands
 *
 * Return: Always 0.
 */

int _print_env(char __attribute__((unused)) **av)
{
	unsigned int i;

	i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
	return (0);
}

/**
 * own_exit - exit
 *
 * @av: buffer with the commands
 *
 * Return: Exit status
 */
int own_exit(char **av)
{

	/* Exit without args */
	if (av[1] == NULL)
	{
		free_grid(av);
		exit(EXIT_SUCCESS);
	}
	return (0);

}

