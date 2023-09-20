#include "shell.h"

/**
 * inbuff -> A function to chadd comm with buf
 *@info: It's a variable struct
 *@buf: It's a place of business
 *@len: It's a Location of Len
 *Return: The data read
 */

ssize_t inbuff(info_t *info, char **buf, size_t *len)
{
	ssize_t b = 0;
	size_t lenp = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigan);
#if USE_GETLINE
		b = getline(buf, &lenp, stdin);
#else
		b = gain(info, buf, &lenp);
#endif
		if (b > 0)
		{
			if ((*buf)[b - 1] == '\n')
			{
				(*buf)[b - 1] = '\0';
				b--;
			}			info->linecount_flag = 1;
			replacecom(*buf);
			baddhl(info, *buf, info->histcount++);
			*len = b;
			info->cmd_buf = buf;
		}
	}	return (b);
}

/**
 * remneli -> A function to remove newline from line
 *@info: It's a variable struct
 *Return: The data read
 */

ssize_t remneli(info_t *info)
{
	static char *buf;
	static size_t x, z, le;
	ssize_t r = 0;
	char **bufp = &(info->arg), *p;

	prichar(BUF_FLUSH);
	r = inbuff(info, &buf, &le);

	if (r == -1)
		return (-1);
	if (le)
	{
		z = x;
		p = buf + x;
		checkch(info, buf, &z, x, le);
		for (; z < le; z++)
		{
			if (ischain(info, buf, &z))
				break;
		}		x = z + 1;
		if (x >= le)
		{
			x = le = 0;
			info->cmd_buf_type = CMD_NORM;
		}		*bufp = p;
		return (lenstr(p));
	}	*bufp = buf;
	return (r);
}

/**
 * reabuf -> A function to read article
 *@info: It's a variable struct
 *@buf: It's a buf
 *@v: It's a variable
 *Return: (b) -> Successful
 */

ssize_t reabuf(info_t *info, char *buf, size_t *v)
{
	ssize_t b = 0;

	if (*v)
	{

		return (0);

	}	b = read(info->readfd, buf, READ_BUF_SIZE);

	if (b >= 0)
	{
		*v = b;

	}	return (b);

}

/**
 * gain -> A function to obtain of input from STDIN
 *@info: It's a variable struct
 *@ptr: It's an address of buffs
 *@length: It's a length
 *Return: If not -> (NULL) || Preallocated pointer buffer's size
 */

int gain(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t x, le;
	size_t z;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (x == le)
		x = le = 0;
	r = reabuf(info, buf, &le);
	if (r == -1 || (r == 0 && le == 0))
		return (-1);
	c = fstrace(buf + x, '\n');
	z = c ? 1 + (unsigned int)(c - buf) : le;
	new_p = relmem(p, s, s ? s + z : z + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);
	if (s)
		coptsr(new_p, buf + x, z - x);
	else
		copsr(new_p, buf + x, z - x + 1);
	s += z - x;
	x = z;
	p = new_p;

	if (length)
	{
		*length = s;
	}	*ptr = p;
	return (s);
}

/**
 * sigan -> A function that use (ctrl-C) stop
 *@sig_num: It's a signal identd
 *Return: VOID
 */

void sigan(__attribute__((unused))int sig_num)
{

	pristr("\n");

	pristr("$ ");

	prichar(BUF_FLUSH);

}
