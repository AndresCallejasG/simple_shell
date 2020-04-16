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
	int num = 0;

	/* Exit without args */
	if (av[1] == NULL)
	{
		free_grid(av);
		return (-1);
	}
	else
	{
		num = _atoi(av[1]);
		if (num == -1)
			return (2);
		free_grid(av);
		exit(num);
	}
	return (0);
}
/**
 * own_help - help
 *
 * @av: buffer with the commands
 *
 * Return: 0 if success otherwise 1
 */
int own_help(char **av)
{

	int i = 0;

	help_t help_list[] = {
		{"exit", help_exit},
		{"env", help_env},
		{"help", help_help},
		{NULL, NULL}};

	if (av[1] == NULL)
	{
		print_help_cmds();
		return (0);
	}

	while (help_list[i].cmd)
	{
		if (_strcmp(av[1], help_list[i].cmd) == 0)
		{
			help_list[i].f();
			return (0);
		}
		i++;
	}
	return (1);
}
