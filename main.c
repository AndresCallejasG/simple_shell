#include "shellh.h"

/**
 * main - Simple_shell main function
 * 
 * @ac: args count
 * @av: args array
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
    char *line;
    size_t len = 0;
    int status = 1;
    /* int j = 0; */
    char **args;
    
    line = malloc(sizeof(char));
    do
    {
        /* Imprime $ y espera el primer comando */
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

    }while (status);
    free(line);
    free(args);

    return (0);
}
