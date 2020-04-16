#include "shellh.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to be copied
 * Return: copied string
 */
char *_strdup(char *str)
{
	int i, len;
	char *str2 = 0;

	if (!str)
		return (NULL);

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));

	if (!str2)
	{
		perror("Malloc failed\n");
		return (NULL);
	}
	for (i = 0; i < len; i++)
		str2[i] = str[i];

	str2[i] = 0;
	return (str2);
}

/**
 * _strcmp - compares two strings.
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if is exactly the same.
 */

int _strcmp(char *s1, char *s2)
{
	int i, dif;

	i = 0;
	dif = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			dif = s1[i] - s2[i];
			return (dif);
		}
		i++;
	}

	return (0);
}
/**
 * _str_concat - concatenate two strings
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
 * _strlen - calculate the lenght of a string
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
