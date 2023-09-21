#include "shell.h"

/**
 * strcop -> A function to copy str
 *@dest: It's a destination
 *@src: It's a source
 *Return: The pointer to destination
 */

char *strcop(char *dest, char *src)
{
	int c = 0;

	if (dest == src || src == 0)

		return (dest);

	while (src[c])
	{
		dest[c] = src[c];

		c++;

	}	dest[c] = 0;

	return (dest);

}

/**
 * dupstr -> A function to duplicate str
 *@str: It's a duplicate str
 *Return: The str reference to replicate text
 */

char *dupstr(const char *str)
{
	int leng = 0;
	char *rep;

	if (str == NULL)

		return (NULL);

	while (*str++)
	{

		leng++;

	}	rep = malloc(sizeof(char) * (leng + 1));

	if (!rep)

		return (NULL);

	for (leng++; leng--;)
	{

		rep[leng] = *--str;

	}	return (rep);

}

/**
 *pristr -> A function to print input str
 *@str: It's a str to print
 *Return: VOID
 */

void pristr(char *str)
{
	int P = 0;

	if (!str)

		return;

	while (str[P] != '\0')
	{

		prichar(str[P]);

		P++;

	}
}

/**
 * prichar -> A function to write char c -> stdout
 *@c: char to print
 *Return: (1)-> If it well, (-1)-> ERRNO is set accordingly
 */

int prichar(char c)
{
	static int p;

	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || p >= WRITE_BUF_SIZE)
	{
		write(1, buf, p);
		p = 0;
	}

	if (c != BUF_FLUSH)
	{

		buf[p++] = c;

	}	return (1);

}
