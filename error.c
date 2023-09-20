#include "shell.h"

/**
 * intostr -> A function to convert str to int
 *@s: It's a str
 *Return: (0)-> convert number || otherwise (-1)-> on ERROR
 */

int intostr(char *s)
{
	int i = 0;
	unsigned long int vert = 0;

	if (*s == '+')
		s++;

	for (i = 0;  s[i] != '\0'; i++)
	{

		if (s[i] >= '0' && s[i] <= '9')
		{
			vert *= 10;
			vert += (s[i] - '0');

			if (vert > INT_MAX)
				return (-1);
		}

		else
			return (-1);

	}	return (vert);

}

/**
 * erroprint -> A function to print ERROR message
 *@info: It's a parameter
 *@estr: It's a str
 *Return: (0)-> convert number || otherwise (-1)-> on ERROR
 */

void erroprint(info_t *info, char *estr)
{
	strpo(info->fname);
	strpo(": ");

	decprint(info->line_count, STDERR_FILENO);

	strpo(": ");
	strpo(info->argv[0]);

	strpo(": ");
	strpo(estr);
}

/**
 * decprint -> A function to print dec
 *@input: It's an input
 *@fd: It's a filed script
 *Return: The num of char -> printed
 */

int decprint(int input, int fd)
{
	int (*__putchar)(char) = prichar;
	int d, countl = 0;
	unsigned int _abs_, curr;

	if (fd == STDERR_FILENO)
		__putchar = addlett;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		countl++;
	}
	else
	{
		_abs_ = input;

	}	curr = _abs_;

	for (d = 1000000000; d > 1; d /= 10)
	{
		if (_abs_ / d)
		{
			__putchar('0' + curr / d);
			countl++;

		}		curr %= d;

	}	__putchar('0' + curr);
	countl++;

	return (countl);
}

/**
 * reconvert -> A function to converter clone of itoa
 *@num: It's a num
 *@base: It's a base
 *@flags: It's an arg flag
 *Return: The str
 */

char *reconvert(long int num, int base, int flags)
{
	static char *arr;
	static char buffs[50];
	char sign = 0;
	char *pion;
	unsigned long re = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		re = -num;
		sign = '-';

	}	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pion = &buffs[49];
	*pion = '\0';

	while (re != 0)
	{
		*--pion = arr[re % base];
		re /= base;
	}

	if (sign)
	{
		*--pion = sign;

	}	return (pion);
}

/**
 * replacecom -> A function to replace 1  of '#' with '\0'
 *@buf: It's an address of str
 *Return: VOID
 */

void replacecom(char *buf)
{
	int r;

	for (r = 0; buf[r] != '\0'; r++)
	{

		if (buf[r] == '#' && (!r || buf[r - 1] == ' '))
		{
			buf[r] = '\0';
			break;
		}
	}
}
