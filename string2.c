#include "shell.h"

/**
 * lenstr -> A function to return length of str
 *@s: It's a str
 *Return: The length of str
 */

int lenstr(char *s)
{
	int l = 0;

	if (!s)

		return (0);

	for (; *s != '\0'; s++)
	{

		l++;

	}	return (l);
}


/**
 * comstr -> A function to compare lexical patterns of 2 different languages
 *@s1: It's 1 str
 *@s2: It's 2 str
 *Return: (0)-> if (s1 == s2) || (+) if (s1 > s2) || (-) if (s1 s2)
 */

int comstr(char *s1, char *s2)
{

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{

			return (*s1 - *s2);

		}		s1++;

		s2++;

	}

	if (*s1 == *s2)

		return (0);

	else

		return (*s1 < *s2 ? -1 : 1);
}

/**
 * nestart -> A function to check needle starts with haystack
 *@haystack: It's a str to search
 *@needle: It's a substr to find
 *Return: The address of next haystack char or (NULL)
 */

char *nestart(const char *haystack, const char *needle)
{

	while (*needle)

		if (*needle++ != *haystack++)

			return (NULL);

	return ((char *)haystack);
}

/**
 * stdest -> A function to join 2 threads
 *@dest: It's a destination
 *@src: It's a source
 *Return: The  pointer to destination
 */

char *stdest(char *dest, char *src)
{
	char *rep = dest;

	while (*dest)

		dest++;

	while (*src)
	{

		*dest++ = *src++;

	}	*dest = *src;

	return (rep);

}
