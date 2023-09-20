#include "shell.h"

/**
 * lenglis -> A function to specifier len
 *@h: It's a reference to root node
 *Return: The length of list
 */

size_t lenglis(const list_t *h)
{
	size_t b = 0;

	for (; h; h = h->next)
	{

		b++;

	}	return (b);

}

/**
 * strtlist -> A function to return list of str
 *@head: It's a reference to root node
 *Return: The multiple str
 */

char **strtlist(list_t *head)
{
	list_t *node = head;
	size_t b = lenglis(head), n;
	char **strs;
	char *str;

	if (!head || !b)
	{
		return (NULL);

	}	strs = malloc(sizeof(char *) * (b + 1));
	if (!strs)
		return (NULL);
	b = 0;
	while (node)
	{
		str = malloc(lenstr(node->str) + 1);
		if (!str)
		{
			for (n = 0; n < b; n++)
				free(strs[n]);
			free(strs);
			return (NULL);

		}		str = strcop(str, node->str);
		strs[b] = str;
		node = node->next;
		b++;

	}	strs[b] = NULL;
	return (strs);
}

/**
 * plist -> A function to display all of components
 *@h: It's a reference to root node
 *Return: The length -> list
 */

size_t plist(const list_t *h)
{
	size_t b = 0;

	for (; h; h = h->next, b++)
	{
		pristr(reconvert(h->num, 10, 0));

		prichar(':');
		prichar(' ');

		pristr(h->str ? h->str : "(nil)");
		pristr("\n");

	}	return (b);

}

/**
 * prefnode -> A function to node whose str prefixes
 *@node: It's an index of list's head
 *@prefix: It's a str matching
 *@c: It's a char after prefix
 *Return: The match (NULL) || nodes
 */

list_t *prefnode(list_t *node, char *prefix, char c)
{
	char *f = NULL;

	for (; node; node = node->next)
	{
		f = nestart(node->str, prefix);

		if (f && ((c == -1) || (*f == c)))

			return (node);

	}	return (NULL);

}

/**
 * retnode -> A function to retrieve node's index
 *@head: It's an index of list's head
 *@node: It's an identifier of node
 *Return: The node index || -> (-1)
 */

ssize_t retnode(list_t *head, list_t *node)
{
	size_t b = 0;

	for (; head; head = head->next, b++)
	{

		if (head == node)

			return (b);

	}	return (-1);
}
