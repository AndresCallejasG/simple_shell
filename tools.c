#include "shellh.h"
/**
 * str_concat - concatenate two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: array concatenated
 */
char *_str_concat(char *s1, char *s2)
{
	char *concat;
	int i, j, len1, len2;

	i = 0;
	j = 0;

	if (s1 == 0)
		s1 = "";
	if (s2 == 0)
		s2 = "";

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	concat = malloc((len1 + len2) * sizeof(char) + 2);

	if (concat == 0)
		return ('\0');

	for (i = 0; i < len1; i++)
	{
		concat[i] = s1[i];
	}
    concat[i++] = '/';
	for (j = 0; j < len2; j++)
	{
		concat[i + j] = s2[j];
	}
	concat[i + j] = '\0';
	return (concat);
}
/**
 * len - calculate the lenght of a string
 *
 * @str: string
 *
 * Return: lenght
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
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
