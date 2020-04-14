#include "shellh.h"
/**
 * add_node_end -  adds a new node at the end of a list_t list.
 *
 * @head: head
 * @str: string
 * Return: list with new node
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_node;
	char *s;
	list_t *current = *head;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	s = _strdup(str);
	if (s == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->str = s;
	new_node->next = NULL;
	if (*head)
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
	}
	else
	{
		*head = new_node;
	}
	return (*head);
}

/**
 * _linkPATH - creates a linked list with PATH elements
 *
 * @head: head of list;
 * Return: Always 0.
 */
list_t *_linkPATH(list_t **head)
{
	char *tok, *name, *s, *s2;
	int i = 0;
	char *tmpenv;

	name = "PATH";

	i = 0;
	while (environ[i])
	{
		/* evita dañar el environ */
		tmpenv = _strdup(environ[i]);

		/* strtok sobre la copia */
		tok = strtok(tmpenv, "=");

		if (_strcmp(name, tok) == 0)
		{
			tok = strtok(NULL, "=");
			/* avoid valgrind error */
			s = _strdup(tok);
			tok = strtok(s, ":");
			while (tok)
			{
				s2 = _strdup(tok);
				add_node_end(head, s2);
				free(s2);
				tok = strtok(NULL, ":");
			}
			free(s);
			free(tmpenv);
			return (*head);
		}
		free(tmpenv);
		i++;
	}
	return (NULL);
}
/**
 * free_list - prints all the elements of a list_t list.
 *
 * @head: List
 *
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *current;

	if (head)
	{
		while (head)
		{
			current = head;
			head = head->next;
			free(current->str);
			free(current);
		}
	}
}

