#include "shell.h"

/**
 * freeaddr -> A function to address and release pointer
 *@ptr: It's an address of free pointer
 *Return: Released -> (1) || otherwise -> (0)
*/

int freeaddr(void **ptr)
{

	if (ptr && *ptr)
	{

		free(*ptr);

		*ptr = NULL;

		return (1);

	}	return (0);

}
