#include "shell.h"

/**
 * nodeadd -> A function to add node to list's begin
 *@head: It's an address of head node pointer
 *@str: It's a field of node str
 *@num: It's a history's node index
 *Return: The length of list
 */

list_t *nodeadd(list_t **head, const char *str, int num)
{
	list_t *nhead;

	if (!head)
	{
		return (NULL);

	}	nhead = malloc(sizeof(list_t));

	if (!nhead)
	{
		return (NULL);

	}	conmem((void *)nhead, 0, sizeof(list_t));
	nhead->num = num;

	if (str)
	{
		nhead->str = dupstr(str);

		if (!nhead->str)
		{
			free(nhead);
			return (NULL);
		}
	}	nhead->next = *head;
	*head = nhead;
	return (nhead);
}

/**
 * addnodend -> A function to add a node to list's end
 *@head: It's an address of head node
 *@str: It's a field of node
 *@num: It's a history's node
 *Return: The length of list
 */

list_t *addnodend(list_t **head, const char *str, int num)
{
	list_t *nnode, *node;

	if (!head)
	{
		return (NULL);

	}	node = *head;
	nnode = malloc(sizeof(list_t));

	if (!nnode)
	{
		return (NULL);
	}	conmem((void *)nnode, 0, sizeof(list_t));
	nnode->num = num;

	if (str)
	{
		nnode->str = dupstr(str);
		if (!nnode->str)
		{
			free(nnode);
			return (NULL);
		}
	}

	for (; node && node->next; node = node->next)
		;

	if (node)
		node->next = nnode;
	else
	{
		*head = nnode;

	}	return (nnode);
}

/**
 * lenlist -> A function to only outputs str
 *@h: It's a reference to root node
 *Return: The length of list
 */

size_t lenlist(const list_t *h)
{

	size_t l = 0;

	for (; h; h = h->next)
	{

		pristr(h->str ? h->str : "(nil)");
		pristr("\n");
		l++;

	}	return (l);

}

/**
 * remnode -> A function to remove node at specified index
 *@head: It's an address of initial node
 *@index: It's an index of deleted node
 *Return: (1) -> for successful & (0) -> Failure
 */

int remnode(list_t **head, unsigned int index)
{
	list_t *node, *prevnode;
	unsigned int n;

	if (!head || !*head)
		return (0);

	if (index == 0)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);

	}	prevnode = *head;
	node = prevnode->next;

	for (n = 1; node; n++)
	{
		if (n == index)
		{
			prevnode->next = node->next;
			free(node->str);
			free(node);
			return (1);

		}		prevnode = node;
		node = node->next;

	}	return (0);
}

/**
 * listfree -> A function to release every node on list
 *@ptrhead: It's an address of head node
 *Return: VOID
 */

void listfree(list_t **ptrhead)
{
	list_t *node, *nnode, *head;

	if (!ptrhead || !*ptrhead)
	{
		return;

	}	head = *ptrhead;

	for (node = head; node; node = nnode)
	{
		nnode = node->next;
		free(node->str);
		free(node);

	}	*ptrhead = NULL;
}
