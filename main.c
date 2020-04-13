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
    int status = 1, interactive = 0;
    /* int j = 0; */
    char **args;
    
    line = malloc(sizeof(char));

    signal(SIGINT, handle_ctrl_c);

    /* revisa si hay una entrada conectada con el stdin */
    if (isatty(STDIN_FILENO) != 0)
            interactive = 1;
    do
    {
        /* Imprime $ y espera el primer comando */
        if(interactive)
            printf("$ ");

        /* lee del stdin, controla ctrl + D */
        if (getline(&line, &len, stdin) == -1) {
            printf("\n");
            continue;
        }

        /*controla lineas vacias*/
        if(strcmp(line, "\n") == 0){
            continue;    
        }

        /* parte la linea y la almacena en un char **str */
        args = _split(line);  

        /* for(j = 0; args[j] != NULL; j++)
        {
            printf("posicion %d ----> %s\n",j , args[j]);
            
        } */

        /*procesa el array de str y ejecuta dependiendo del tipo */
        status = _processing(args);      

    }while (status && interactive);
    free(line);
    free(args);

    return (0);
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
