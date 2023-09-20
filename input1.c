#include "shell.h"

/**
 * active -> A function that shell is in active mode or not
 *@info: It's an address in struct
 *Return: (1)-> Mode is activated || (0)-> otherwise
 */

int active(info_t *info)
{

	return (isatty(STDIN_FILENO) && info->readfd <= 2);

}

/**
 * ist_de -> A function to determine char is delimeter
 *@c: It's a char to check
 *@deli: It's a str of delimeter
 *Return: (0) -> false || (1) -> true
 */

int ist_de(char c, char *deli)
{
	while (*deli)

		if (*deli++ == c)
		{

			return (1);

		}	return (0);
}

/**
 *alphaa -> A function to make alpha char check
 *@c: It's an input char
 *Return: (0) -> else || (1) -> c is alpha
 */

int alphaa(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

		return (1);

	else
	{

		return (0);

	}
}

/**
 *intfs -> A function to create integer from str
 *@s: It's a str being transformed
 *Return: (0)-> str contains || else converted num
 */

int intfs(char *s)
{
	int x = 0, sign = 1, flag = 0, bas;
	unsigned int rs = 0;

	while (s[x] != '\0' && flag != 2)
	{
		if (s[x] == '-')
			sign *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			rs *= 10;
			rs += (s[x] - '0');
		}

		else if (flag == 1)
		{
			flag = 2;
		}		x++;
	}

	if (sign == -1)
		bas = -rs;
	else
	{
		bas = rs;

	}	return (bas);

}
