#include "shellh.h"

/**
 * main - Simple_shell main function
 * 
 * @ac: args count
 * @av: args array
 *
 * Return: Always 0.
 */
int main(void)
{
    char *line;
    size_t len = 0;
    int status = 1;
    /* int j = 0; */
    char **args;

    signal(SIGINT, handle_ctrl_c);

    /* revisa si hay una entrada conectada con el stdin */
    if (isatty(STDIN_FILENO) != 0)
    {

        do
        {
            line = malloc(sizeof(char));
            /* Imprime $ y espera el primer comando */
            printf("$ ");

            /* lee del stdin, controla ctrl + D */
            if (getline(&line, &len, stdin) == -1)
            {
                free(line);
                _putchar('\n');
                break;
            }

            /*controla lineas vacias*/
            if (strcmp(line, "\n") == 0)
            {
                free(line);
                continue;
            }

            /* parte la linea y la almacena en un char **str */
            args = _split(line);

            free(line);

            /* for(j = 0; args[j] != NULL; j++)
        {
            printf("posicion %d ----> %s\n",j , args[j]);
            
        } */

            /*procesa el array de str y ejecuta dependiendo del tipo */
            status = _processing(args);

        } while (status);
        free(args);

    }
    else
    {
        non_interactive();
    }
    return (0);
}

void non_interactive(void)
{
    char *line;
    size_t len = 0;
    int status = 0, line_status = 0;
    char **args;

    do
    {
        line = malloc(sizeof(char));
        line_status = getline(&line, &len, stdin);
        if (line_status == -1)
            {
                free(line);
                _putchar('\n');
                break;
            }

            /*controla lineas vacias*/
            if (strcmp(line, "\n") == 0)
            {
                free(line);
                continue;
            }

            /* parte la linea y la almacena en un char **str */
            args = _split(line);

            free(line);
            
            /*procesa el array de str y ejecuta dependiendo del tipo */
            status = _processing(args);

    } while (line_status != -1);
    free(args);
    exit(status);
}

/**
 * sign_handler - handles the abscensce of a sign
 * @sig: integer
 */
void handle_ctrl_c(int sign)
{
    sign = sign * 1;
    _putchar('\n');
    _putchar('$');
    _putchar(' ');
}
