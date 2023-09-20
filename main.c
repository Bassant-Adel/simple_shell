#include "shell.h"

/**
 * main -> A function to point
 *@ac: It's an arg count
 *@av: It's an arg vector
 *Return: (0) -> successful || (1) -> (ERROR)
*/

int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm volatile (
			"mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd)
			);

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);

		if (fd == -1)
		{
			if (errno == EACCES)
			{
				exit(126);

			}

			if (errno == ENOENT)
			{
				strpo(av[0]);
				strpo(": 0: Can't open ");
				strpo(av[1]);
				addlett('\n');
				addlett(BUF_FLUSH);
				exit(127);

			}			return (EXIT_FAILURE);

		}		info->readfd = fd;

	}	envfill(info);
	readhis(info);
	hsh(info, av);

	return (EXIT_SUCCESS);
}
