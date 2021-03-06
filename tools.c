#include "shellh.h"
/**
 * free_grid - free 2D array
 *
 * @grid: array
 *
 * Return: void
 */

void free_grid(char **grid)
{
	int i;

	i = 0;

	for (i = 0; grid[i] != NULL; i++)
		free(grid[i]);
	free(grid);
}

/**
* _atoi - convert a string to an integer
* @s: string
*
* Return: num if finds a number
* 0 otherwise
*/

int _atoi(char *s)
{
	int i;
	int num;

	i = 0;
	num = 0;

	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num *= 10;
				num -= (s[i] - '0');
			}
			else
				return (-1);
			i++;
		}
		return (num * -1);
	}
	return (-1);
}
