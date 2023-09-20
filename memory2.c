#include "shell.h"

/**
 * conmem -> A function to give memory constant
 *@s: It's a memory
 *@b: It's a byte
 *@n: It's a number
 *Return: (s)-> reference to memory location
 */

char *conmem(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{

		s[a] = b;

	}	return (s);

}

/**
 * relst -> A function to release group of str
 *@pp: It's a str
 *Return: VOID
 */

void relst(char **pp)
{
	char **b = pp;

	if (!pp)

		return;

	while (*pp)
	{

		free(*pp++);

	}	free(b);
}

/**
 * relmem -> A function to reallocate memory
 *@ptr: It's an identifier of previously
 *@oldsi: It's a old size
 *@newsi: It's a new size
 *Return: The reference to old block
 */

void *relmem(void *ptr, unsigned int oldsi, unsigned int newsi)
{
	char *a;

	if (!ptr)

		return (malloc(newsi));

	if (!newsi)

		return (free(ptr), NULL);

	if (newsi == oldsi)
	{
		return (ptr);

	}	a = malloc(newsi);

	if (!a)
	{
		return (NULL);

	}	oldsi = oldsi < newsi ? oldsi : newsi;

	while (oldsi--)
	{

		a[oldsi] = ((char *)ptr)[oldsi];

	}	free(ptr);
	return (a);
}
