#include "shellh.h"
/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string.
 *
 * @str: *char to print.
 *
 * Return: void.
 */
int _puts(char *str)
{
	return (write(1, str, _strlen(str)));
}
/**
* _print_number - prints an integer char by char
* @n: The integer to print
*
* Return: void
*/

void _print_number(int n)
{
	int i, size;
	unsigned int num, num_temp, dig, div;

	num = n;
	size = 0;
	div = 1;

	if (n < 0)
	{
		num = num * -1;
		_putchar(45);
	}

	num_temp = num;
	while (num_temp != 0)
	{
		size++;
		num_temp /= 10;
	}
	for (i = 1; i < size; i++)
	{
		div = div * 10;
	}
	for (i = size - 1; i >= 1; i--)
	{
		dig = num / div;
		_putchar((dig % 10) + '0');
		div /= 10;
	}
	_putchar((num % 10) + '0');
}
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
