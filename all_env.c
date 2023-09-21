#include "shell.h"

/**
 * prienv -> A function to print current environment
 *@info: It's a structure
 *Return: (0)-> Successful
 */

int prienv(info_t *info)
{
	list_t *curenv = info->env;

	for (; curenv != NULL; curenv = curenv->next)
	{
		pristr(curenv->str);
		prichar('\n');

	}	return (0);

}

/**
 * geetenv -> A function to get value of environ
 *@info: It's an argument used to keep up
 *@name: It's a name
 *Return: The Value (NULL)
 */

char *geetenv(info_t *info, const char *name)
{
	list_t *anode = info->env;
	char *e;

	for (; anode != NULL; anode = anode->next)
	{
		e = nestart(anode->str, name);

		if (e && *e)
		{
			return (e);
		}

	}	return (NULL);

}

/**
 * envsset -> A function to initialize new environment or modify existing
 *@info: It's an argument
 *Return: Always (0) Successful
 */

int envsset(info_t *info)
{
	if (info->argc != 3)
	{
		strpo("Incorrect number of arguments\n");
		return (1);
	}

	if (envinit(info, info->argv[1], info->argv[2]))
	{

		return (0);

	}	return (1);

}

/**
 * envunsset -> A function to remove environment
 *@info: It's an argument
 *Return: Always (0) Successful
 */

int envunsset(info_t *info)
{
	int e;

	if (info->argc == 1)
	{
		strpo("Too few arguments.\n");
		return (1);
	}

	for (e = 1; e < info->argc; e++)
	{

		remenv(info, info->argv[e]);

	}	return (0);

}

/**
 * envfill -> A function to fill in env
 *@info: It's an argument
 *Return: Always (0) Successful
 */

int envfill(info_t *info)
{
	list_t *anode = NULL;
	size_t f;

	for (f = 0; environ[f]; f++)
	{

		addnodend(&anode, environ[f], 0);

	}	info->env = anode;

	return (0);

}
