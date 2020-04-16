#include "shellh.h"

/**
 * main - Simple_shell main function
 *
 * @argc: args count;
 * @av: args;
 *
 * Return: Always 0.
 */
int main(int __attribute__((unused)) argc, char *av[])
{
	char *line, **args;
	size_t len = 0;
	int interactive = 0, count = 0, status = 0, last_status = 0;

	signal(SIGINT, handle_ctrl_c);
	/* revisa si hay una entrada conectada con el stdin */
	if (isatty(STDIN_FILENO) != 0)
		interactive = 1;
	while (1)
	{
		count++;
		line = 0;
		/* Imprime $ y espera el primer comando */
		if (interactive)
			_puts("$ ");
		/* lee del stdin, controla ctrl + D */
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			if (interactive)
				_putchar('\n');
			break;
		}
		args = 0;
		args = _split(line); /* parte la linea y la guarda en array*/
		if (args[0] == NULL)
		{
			free(line);
			free_grid(args);
			continue;
		}
		free(line);
		last_status = status;
		status = _processing(args); /*proc array de str y ejec segun el tipo */
		if (status == -1)
			exit(last_status);
		print_error(status, args, count, av[0]);
		free_grid(args);
	}
	return (status);
}

/**
 * handle_ctrl_c - handles ctrl + C
 * @sign: integer
 */
void handle_ctrl_c(int sign)
{
	sign = sign * 1;
	_putchar('\n');
	_putchar('$');
	_putchar(' ');
}

void print_error(int status, char **args, int count,
				 char *shell_name)
{
	if (status != 0)
	{
		if (status == 2 && (_strcmp(args[0], "exit") != 0))
			return;
		_puts(shell_name);
		_puts(": ");
		_print_number(count);
		_puts(": ");
		_puts(args[0]);
		_puts(": ");

		switch (status)
		{
			case 2:
				_puts("Illegal number");
				if (args[1])
				{
					_puts(": ");
					_puts(args[1]);
					_puts("\n");
				}
				break;
			case 127:
				_puts("not found");
				_puts("\n");
				break;
			default:
				break;
		}
	}
}
