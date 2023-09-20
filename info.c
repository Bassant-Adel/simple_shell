#include "shell.h"

/**
 * infostab -> A function to establish info_t
 *@info: It's an address
 *Return: VOID
 */

void infostab(info_t *info)
{

	info->arg = NULL;

	info->argv = NULL;

	info->path = NULL;

	info->argc = 0;

}

/**
 * setinfo -> A function to establish info_t
 *@info: It's an address
 *@av: It's an arg type
 *Return: VOID
 */

void setinfo(info_t *info, char **av)
{
	int f = 0;

	info->fname = av[0];

	if (info->arg)
	{
		info->argv = divstr(info->arg, " \t");

		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);

			if (info->argv)
			{
				info->argv[0] = dupstr(info->arg);
				info->argv[1] = NULL;
			}
		}

		for (f = 0; info->argv && info->argv[f]; f++)
			;
		info->argc = f;
		aliasreplace(info);
		bvreplace(info);
	}
}

/**
 * inforel -> A function to release info_t
 *@info: It's an address
 *@all: It's a true -> all fields are freed
 *Return: VOID
 */

void inforel(info_t *info, int all)
{
	relst(info->argv);
	info->argv = NULL;
	info->path = NULL;

	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);

		if (info->env)
			listfree(&(info->env));

		if (info->history)
			listfree(&(info->history));

		if (info->alias)
		{

			listfree(&(info->alias));

		}		relst(info->environ);

		info->environ = NULL;
		freeaddr((void **)info->cmd_buf);

		if (info->readfd > 2)
		{

			close(info->readfd);

		}		prichar(BUF_FLUSH);
	}
}
