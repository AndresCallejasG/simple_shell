#include "shellh.h"

/**
 * _strtok - auxizes a string and turn to array
 *
 * @s: string from getline
 *
 * @del: " ";
 *
 * Return: individual aux in array format
 */

char *_strtok(char *s, char *del)
{
	char *aux = NULL;
	static char *ptraux;

	if (s == NULL)
	{
		s = ptraux;
		if (s == NULL)
		{
			return (NULL);
		}
	}

	s += _strspn(s, del);
	if (*s == '\0')
	{
		ptraux = NULL;
		return (NULL);
	}
	aux = s;
	s = strpbrk(aux, del);
	if (s != NULL)
	{
		*s = '\0';
		ptraux = s + 1;
	}
	else
	{
		ptraux = NULL;
	}
	return (aux);
}

/**
 * _strspn - gets the length of a prefix substring
 *
 * @s: input pointer char
 *
 * @accept: input pointer char
 *
 * Return: unisigned
 */

unsigned int _strspn(char *s, char *accept)
{
	int k = 0, m = 0;
	int c = 0, b = 0;

	while (s[k] != '\0')
	{
		m = 0;
		b = 1;
		while (accept[m] != '\0')
		{
			if (s[k] == accept[m])
			{
				c++;
				b = 0;
			}
			m++;
		}
		if (b == 1)
		{
			break;
		}
	k++;
	}

	return (c);
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 *
 * @s: value input pointer
 *
 * @accept: value input pointer
 *
 * Return: variable char
 */

char *_strpbrk(char *s, char *accept)
{
	int k = 0, m = 0;
	int b = 0, e = 0;

	while (s[k] != '\0')
	{
		m = 0;
		b = 1;
		while (accept[m] != '\0')
		{
			if (s[k] == accept[m])
			{
				b = 0;
				e = k;
			}
			m++;
			if (b == 0)
			{
				return (&s[e]);
			}
		}
		k++;
	}
	return ('\0');
}
