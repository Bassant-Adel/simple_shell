#include "shell.h"

/**
 * strpo -> A function to print a str of input
 *@str: It's a str that print
 *Return: VOID
 */

void strpo(char *str)
{
	int p = 0;

	if (!str)

		return;

	while (str[p] != '\0')
	{

		addlett(str[p]);
		p++;

	}
}

/**
 * addlett -> A function to add letter C
 *@c: It's a text to print
 *Return: Regarding achievement -> (1) || On ERROR -> (-1)
 */

int addlett(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}

	if (c != BUF_FLUSH)
	{

		buf[a++] = c;

	}	return (1);
}

/**
 * fdlett -> A function to write letter C to specify fd
 *@c: It's a text to print
 *@fd: It's an address to write
 *Return: Regarding achievement -> (1) || On ERROR -> (-1)
 */

int fdlett(char c, int fd)
{
	static int f;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || f >= WRITE_BUF_SIZE)
	{
		write(fd, buf, f);
		f = 0;
	}

	if (c != BUF_FLUSH)
	{

		buf[f++] = c;

	}	return (1);
}

/**
 * stipri -> A function to print str of input
 *@str: It's a str that print
 *@fd: It's an address to contact
 *Return: The str
 */

int stipri(char *str, int fd)
{
	int s = 0;

	if (!str)

		return (0);

	while (*str)
	{

		s += fdlett(*str++, fd);

	}	return (s);
}
