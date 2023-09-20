#include "shell.h"

/**
 * gethisf -> A function to obtain history file
 *@info: It's a variable struct
 *Return: The history file in allocated str
 */

char *gethisf(info_t *info)
{
	char *buf, *doo;

	doo = getenv(info, "HOME=");

	if (!doo)
	{
		return (NULL);

	}	buf = malloc(sizeof(char) * (lenstr(doo) + lenstr(HIST_FILE) + 2));

	if (!buf)
	{
		return (NULL);

	}	buf[0] = 0;

	strcop(buf, doo);
	stdest(buf, "/");
	stdest(buf, HIST_FILE);
	return (buf);
}

/**
 * writehis -> A function to create 1 file
 *@info: It's a struct of para
 *Return: (1) -> successful || (-1) -> otherwise
 */

int writehis(info_t *info)
{
	ssize_t wr;
	char *filename = gethisf(info);
	list_t *node = NULL;

	if (!filename)
	{
		return (-1);

	}	wr = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);

	if (wr == -1)
		return (-1);

	for (node = info->history; node; node = node->next)
	{
		stipri(node->str, wr);
		fdlett('\n', wr);

	}	fdlett(BUF_FLUSH, wr);
	close(wr);
	return (1);
}

/**
 * readhis -> A function to read file history
 *@info: It's a struct of parameters
 *Return: if successful || otherwise -> (0)
 */

int readhis(info_t *info)
{
	int b, last = 0, linecount = 0;
	ssize_t fd, rale, fsi = 0;
	struct stat st;
	char *buf = NULL, *filename = gethisf(info);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsi = st.st_size;
	if (fsi < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsi + 1));
	if (!buf)
		return (0);
	rale = read(fd, buf, fsi);
	buf[fsi] = 0;
	if (rale <= 0)
	{
		return (free(buf), 0);
	}	close(fd);

	for (b = 0; b < fsi; b++)
		if (buf[b] == '\n')
		{
			buf[b] = 0;
			baddhl(info, buf + last, linecount++);
			last = b + 1;
		}
	if (last != b)
		baddhl(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		remnode(&(info->history), 0);
	hisrem(info);
	return (info->histcount);
}

/**
 * baddhl -> A function to create new entry in history
 *@info: It's a arrangement with potential arg
 *@buf: It's a buf
 *@linecount: It's a linecount of history
 *Return: Never -> (1)
 */

int baddhl(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
	{
		node = info->history;

	}	addnodend(&node, buf, linecount);

	if (!info->history)
	{
		info->history = node;

	}	return (0);

}

/**
 * hisrem -> A function that after revisions
 *@info: It's a arrangement with potential arg
 *Return: A update headcount
 */

int hisrem(info_t *info)
{
	list_t *node = info->history;
	int b = 0;

	while (node)
	{

		node->num = b++;
		node = node->next;

	}	return (info->histcount = b);

}
