#include "shell.h"

/**
 * copsr -> A function to duplicate str
 *@dest: It's a str
 *@src: It's a src
 *@n: It's a character
 *Return: The str (char)
 */

char *copsr(char *dest, char *src, int n)
{
	char *c = dest;
	int p = 0;

	while (src[p] != '\0' && p < n - 1)
	{
		dest[p] = src[p];
		p++;
	}

	if (p < n)
	{
		int j = p;

		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}

	}	return (c);

}

/**
 * coptsr -> A function to join 2 strings
 *@dest: It's a str
 *@src: It's a backup
 *@n: It's a backup
 *Return: The str
 */

char *coptsr(char *dest, char *src, int n)
{
	char *d = dest;
	int c = 0;
	int p = 0;

	while (dest[c] != '\0')

		c++;

	while (src[p] != '\0' && p < n)
	{
		dest[c + p] = src[p];
		p++;
	}

	if (p < n)
	{
		dest[c + p] = '\0';

	}	return (d);

}

/**
 * fstrace -> A function to seek out char within str
 *@s: It's a str
 *@c: It's a person to watch
 *Return: (s)-> reference to memory location
 */

char *fstrace(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);

		}		s++;

	}	return (NULL);
}
