#include "shellh.h"

/**
 * _split - print all args
 *
 * @line: char *str from stdin
 * Return: *args[] or NULL if line == NULL.
 */
char **_split(char *line)
{
    char *str, *str2, *str3;
    char **array, *tok;
    int i = 0; /* , j = 0 */

    if (line)
    {
        /* duplicate str to avoid strtok damage and delete /n */
        str = strdup(strtok(line, "\n"));
        str2 = strdup(str);

        tok = strtok(str, " ");

        /* count number of tokens */
        while (tok != NULL)
        {
            i++;
            tok = strtok(NULL, " ");
        }
        array = malloc(sizeof(char *) * (i + 1));
        tok = strtok(str2, " ");
        i = 0;

        /* fill array with each token */
        while (tok != NULL)
        {
            str3 = strdup(tok);
            array[i] = malloc(sizeof(char) * strlen(str3));
            array[i] = str3;
            i++;
            tok = strtok(NULL, " ");
        }
        array[i] = NULL;
        
        /* instead of return - print */
        /* for(j = 0; j < i; j++)
        {
            printf("%s\n", array[j]);
        }
 */
        /* free memory */
        free(str);
        free(str2);
        return (array);

        /* instead of return - print */
        /* for(j = 0; j < i; j++)
        {
            printf("%s\n", array[j]);
        } */
    }

    return (NULL);
}

/**
 * _processing - process args and choose how to execute it
 *
 * @args: char **str
 * Return: *args[] or NULL if line == NULL.
 */
int _processing(char **args){

    int i = 0;

    built_in_t b_in[] = {
		{"exit", own_exit},
		{"env", _print_env},
		{NULL, NULL}
	};
    
    while (b_in[i].cmd)
	{
		if (strcmp(args[0], b_in[i].cmd) == 0)
		{
			return (b_in[i].f(args));
		}
		i++;
	}
    
    _execve(args);   
    return (1);
}