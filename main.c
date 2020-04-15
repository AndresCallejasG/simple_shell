#include "shellh.h"

/**
 * main - Simple_shell main function
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line, **args;
	size_t len = 0;
	int interactive = 0, status = 0;

	signal(SIGINT, handle_ctrl_c);

	/* revisa si hay una entrada conectada con el stdin */
	if (isatty(STDIN_FILENO) != 0)
		interactive = 1;

	while (1)
	{
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
		status = _processing(args); /*proc array de str y ejec segun el tipo */
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
