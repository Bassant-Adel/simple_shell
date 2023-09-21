#include "shell.h"

/**
 * cpenviron -> A function to return str array copy
 *@info: It's a structure
 *Return: (0)-> Successful
 */

char **cpenviron(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = strtlist(info->env);
		info->env_changed = 0;

	}	return (info->environ);

}

/**
 * remenv -> A function to Remove environment
 *@info: It's a structure
 *@var: It's a str env
 *Return: (1)-> on delete, (0)-> otherwise
 */

int remenv(info_t *info, char *var)
{
	list_t *anode = info->env;
	size_t r = 0;
	char *e;

	if (!anode || !var)
		return (0);

	for (; anode; anode = anode->next, r++)
	{
		e = nestart(anode->str, var);

		if (e && *e == '=')
		{
			info->env_changed = remnode(&(info->env), r);
			r = 0;
			anode = info->env;
			continue;
		}

	}	return (info->env_changed);

}

/**
 * envinit -> A function to initialize new environment
 *@info: It's an argument
 *@var: It's a str env
 *@value: It's a str env
 *Return: Always (0)-> Successful
 */

int envinit(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *anode;
	char *e;

	if (!var || !value)
	{
		return (0);

	}	buf = malloc(lenstr(var) + lenstr(value) + 2);

	if (!buf)
	{

		return (1);

	}	strcop(buf, var);
	stdest(buf, "=");
	stdest(buf, value);
	anode = info->env;

	for (; anode; anode = anode->next)
	{
		e = nestart(anode->str, var);

		if (e && *e == '=')
		{
			free(anode->str);
			anode->str = buf;
			info->env_changed = 1;
			return (0);
		}
	}	addnodend(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
