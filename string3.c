#include "shell.h"

/**
 * divstr -> A function to make word divisions in str ignores repeated delim
 *@str: It's an input str
 *@d: It's a delimeter str
 *Return: The pointer to str array || (NULL) -> Failure
 */

char **divstr(char *str, char *d)
{
	int x, y, z, n, ittem = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!ist_de(str[x], d) && (ist_de(str[x + 1], d) || !str[x + 1]))
			ittem++;

	if (ittem == 0)
		return (NULL);
	t = malloc((1 + ittem) * sizeof(char *));
	if (!t)
		return (NULL);
	for (x = 0, y = 0; y < ittem; y++)
	{
		while (ist_de(str[x], d))
			x++;
		z = 0;
		while (!ist_de(str[x + z], d) && str[x + z])
		{
			z++;
		}		t[y] = malloc((z + 1) * sizeof(char));

		if (!t[y])
		{
			for (z = 0; z < y; z++)
			{
				free(t[z]);
			}			free(t);
			return (NULL);
		}
		for (n = 0; n < z; n++)
			t[y][n] = str[x++];
		t[y][n] = 0;

	}	t[y] = NULL;
	return (t);
}

/**
 * delstr -> A function to separate words -> str
 *@str: It's an input str
 *@d: It's a delimeter
 *Return: The pointer to str array || (NULL) -> Failure
 */

char **delstr(char *str, char d)
{
	int x, y, z, n, ittem = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
				(str[x] != d && !str[x + 1]) || str[x + 1] == d)
			ittem++;
	if (ittem == 0)
		return (NULL);
	t = malloc((1 + ittem) * sizeof(char *));
	if (!t)
		return (NULL);
	for (x = 0, y = 0; y < ittem; y++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		z = 0;
		while (str[x + z] != d && str[x + z] && str[x + z] != d)
		{
			z++;
		}		t[y] = malloc((z + 1) * sizeof(char));

		if (!t[y])
		{
			for (z = 0; z < y; z++)
			{
				free(t[z]);
			}			free(t);
			return (NULL);
		}
		for (n = 0; n < z; n++)
			t[y][n] = str[x++];
		t[y][n] = 0;

	}	t[y] = NULL;
	return (t);
}
