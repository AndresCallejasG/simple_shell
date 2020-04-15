#include "shellh.h"

/**
 * _split - print all args
 *
 * @line: char *str from stdin
 * Return: *args[] or NULL if line == NULL.
 */
char **_split(char *line)
{
	char *str = 0, *str2 = 0;
	char **array = 0, *tok = 0;
	int i = 0; /* , j = 0 */

	if (line)
	{
		/* duplicate str to avoid strtok damage and delete /n */
		str = _strdup(line);
		str2 = _strdup(str);

		tok = strtok(str, " \t\r\n\a");

		/* count number of tokens */
		while (tok != NULL)
		{
			i++;
			tok = strtok(NULL, " \t\r\n\a");
		}
		array = malloc(sizeof(char *) * (i + 1));
		tok = strtok(str2, " \t\r\n\a");
		i = 0;

		/* fill array with each token */
		while (tok != NULL)
		{
			array[i] = _strdup(tok);
			i++;
			tok = strtok(NULL, " \t\r\n\a");
		}
		array[i] = NULL;

		/* free memory */
		free(str);
		free(str2);
		return (array);
	}

	return (NULL);
}

/**
 * _processing - process args and choose how to execute it
 *
 * @args: char **str
 * Return: *args[] or NULL if line == NULL.
 */
int _processing(char **args)
{

	int i = 0;

	built_in_t b_in[] = {
		{"exit", own_exit},
		{"env", _print_env},
		{NULL, NULL}};

	while (b_in[i].cmd)
	{
		if (_strcmp(args[0], b_in[i].cmd) == 0)
		{
			return (b_in[i].f(args));
		}
		i++;
	}

	_execve(args);
	return (0);
}
