#include "shell.h"

/**
 * ischain -> A function to test if current char in buffer is chain delimeter
 *@info: It's a parameter
 *@buf: It's a char buffer
 *@p: It's an address of current position
 *Return: (1)-> if chain delimeter, (0)-> otherwise
 */

int ischain(info_t *info, char *buf, size_t *p)
{
	size_t c = *p;

	if (buf[c] == '|' && buf[c + 1] == '|')
	{
		buf[c] = 0;
		c++;
		info->cmd_buf_type = CMD_OR;
	}

	else if (buf[c] == '&' && buf[c + 1] == '&')
	{
		buf[c] = 0;
		c++;
		info->cmd_buf_type = CMD_AND;
	}

	else if (buf[c] == ';')
	{
		buf[c] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}

	else
	{

		return (0);

	}	*p = c;

	return (1);
}

/**
 * checkch -> A function to check determine chain
 *@info: It's a parameter struct
 *@buf: It's a char buffer
 *@p: It's a current buffer
 *@v: It's a start position in buffer
 *@len: It's a length of buffer
 *Return: VOID
 */

void checkch(info_t *info, char *buf, size_t *p, size_t v, size_t len)
{
	size_t c = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[v] = 0;
			c = len;
		}
	}

	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[v] = 0;
			c = len;
		}

	}	*p = c;
}

/**
 * aliasreplace -> A function that tokenized str, swap out alias
 *@info: It's a parameter
 *Return: (1)-> if replaced, (0)-> otherwise
 */

int aliasreplace(info_t *info)
{
	int r;
	list_t *anode;
	char *a;

	for (r = 0; r < 10; r++)
	{
		anode = prefnode(info->alias, info->argv[0], '=');

		if (!anode)
		{
			return (0);

		}		free(info->argv[0]);

		a = fstrace(anode->str, '=');

		if (!a)
		{
			return (0);

		}		a = dupstr(a + 1);

		if (!a)
		{
			return (0);

		}		info->argv[0] = a;

	}	return (1);

}

/**
 * bvreplace -> A function to replace in the tokenized str
 *@info: It's a parameter
 *Return: (1)-> if replaced, (0)-> otherwise
 */

int bvreplace(info_t *info)
{
	int r = 0;
	list_t *anode;

	while (info->argv[r])
	{
		if (info->argv[r][0] != '$' || !info->argv[r][1])
		{
			r++;
			continue;
		}

		if (!comstr(info->argv[r], "$?"))
		{
			replacestr(&(info->argv[r]),
					dupstr(reconvert(info->status, 10, 0)));
			r++;
			continue;
		}

		if (!comstr(info->argv[r], "$$"))
		{
			replacestr(&(info->argv[r]), dupstr(reconvert(getpid(), 10, 0)));
			r++;
			continue;

		}		anode = prefnode(info->env, &info->argv[r][1], '=');

		if (anode)
		{
			replacestr(&(info->argv[r]), dupstr(fstrace(anode->str, '=') + 1));
		}
		else
		{
			replacestr(&info->argv[r], dupstr(""));

		}		r++;

	}	return (0);
}

/**
 * replacestr -> A function to replace str
 *@old: It's an old str
 *@new: It's a new str
 *Return: (1)-> if replaced, (0)-> otherwise
 */

int replacestr(char **old, char *new)
{
	free(*old);

	*old = new;

	return (1);
}
