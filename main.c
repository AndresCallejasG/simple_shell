#include "shellh.h"

/**
 * main - Simple_shell main function
 *
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line, **args;
	size_t len = 0;
	int status = 1;


	signal(SIGINT, handle_ctrl_c);

	/* revisa si hay una entrada conectada con el stdin */
	if (isatty(STDIN_FILENO) != 0)
	{
		do {
			line = 0;

			/* Imprime $ y espera el primer comando */
			_puts("$ ");

			/* lee del stdin, controla ctrl + D */
			if (getline(&line, &len, stdin) == -1)
			{
				free(line);
				_putchar('\n');
				break;
			}
			/*controla lineas vacias*/
			if (_strcmp(line, "\n") == 0)
			{
				free(line);
				continue;
			}
			/* parte la linea y la almacena en un char **str */
			args = _split(line);
			free(line);

			/*procesa el array de str y ejecuta dependiendo del tipo */
			status = _processing(args);
			free(args);

		} while (status);
	}
	else
		non_interactive();
	return (0);
}
/**
 * non_interactive - main for non-intec
 *
 *
 * Return: Always 0.
 */

void non_interactive(void)
{
	char *line;
	size_t len = 0;
	int status = 0, line_status = 0;
	char **args;

	while (1)
	{
		line = 0;
		line_status = getline(&line, &len, stdin);
		if (line_status == -1)
		{
			free(line);
			break;
		}

		/*controla lineas vacias*/
		if (_strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}

		/* parte la linea y la almacena en un char **str */
		args = _split(line);

		free(line);

		/*procesa el array de str y ejecuta dependiendo del tipo */
		status = _processing(args);
		free(args);
	}

	exit(status);
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
