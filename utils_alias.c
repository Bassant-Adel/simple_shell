#include "shell.h"

/**
 * rhistory -> A function to display history list
 *@info: It's an argument
 *Return: On success -> (0)
 */

int rhistory(info_t *info)
{
	plist(info->history);

	return (0);
}

/**
 * alias_unset -> A function to transform alias to str
 *@info: It's a parameter
 *@str: It's a str alias
 *Return: If successful Return -> (0), If not Return -> (1)
 */

int alias_unset(info_t *info, char *str)
{
	char *a, b;
	int par;

	a = fstrace(str, '=');

	if (!a)
	{

		return (1);

	}	b = *a;

	*a = 0;

	par = remnode(&(info->alias),
			retnode(info->alias, prefnode(info->alias, str, -1)));

	*a = b;
	return (par);
}

/**
 * alias_set -> A function to set alias to str
 *@info: It's a parameter
 *@str: It's a str alias
 *Return: If successful Return -> (0), If not Return -> (1)
 */

int alias_set(info_t *info, char *str)
{
	char *n;

	n = fstrace(str, '=');

	if (!n)
		return (1);

	if (!*++n)
	{

		return (alias_unset(info, str));

	}	alias_unset(info, str);

	return (addnodend(&(info->alias), str, 0) == NULL);
}

/**
 * paliasstr -> A function to print an alias str
 *@node: It's an alias node
 *Return: If successful Return -> (0), If not Return -> (1)
 */

int paliasstr(list_t *node)
{
	char *x = NULL, *s = NULL;

	if (node)
	{
		x = fstrace(node->str, '=');

		while (s <= x)
		{

			prichar(*s++);

		}		prichar('\'');
		pristr(x + 1);
		pristr("'\n");
		return (0);

	}	return (1);
}

/**
 * halias -> A function to help alias
 *@info: It's an argument
 *Return: On success -> (0)
 */

int halias(info_t *info)
{
	int h = 0;
	char *a = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;

		while (node)
		{
			paliasstr(node);
			node = node->next;

		}		return (0);
	}

	for (h = 1; info->argv[h]; h++)
	{
		a = fstrace(info->argv[h], '=');

		if (a)
		{
			alias_set(info, info->argv[h]);
		}

		else
		{
			paliasstr(prefnode(info->alias, info->argv[h], '='));
		}

	}	return (0);
}
