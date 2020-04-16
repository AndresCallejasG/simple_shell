#include "shellh.h"
/**
* _putchar - writes the character c to stdout
*
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately
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
* _print_number_err - prints an integer char by char
*
* in the STDERR_FILENO
*
* @n: The integer to print
*
* Return: void
*/

void _print_number_err(int n)
{
	int i, size;
	unsigned int num, num_temp, dig, div;

	num = n;
	size = 0;
	div = 1;

	if (n < 0)
	{
		num = num * -1;
		_putchar_err(45);
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
		_putchar_err((dig % 10) + '0');
		div /= 10;
	}
	_putchar_err((num % 10) + '0');
}

/**
 * _puts_err - Prints a string to the STDERR_FILENO.
 *
 * @str: *char to print.
 *
 * Return: void.
 */
int _puts_err(char *str)
{
	return (write(STDERR_FILENO, str, _strlen(str)));
}

/**
* _putchar_err - writes the character c to stdout
*
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar_err(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
