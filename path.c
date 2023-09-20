#include "shell.h"

/**
 * execomd -> A function to test file if it executable command
 *@info: It's a data structure
 *@path: It's an URL of file
 *Return: (0) -> False || (1)-> True
 */

int execomd(info_t *info, char *path)
{
	struct stat st;

	(void)info;

	if (!path || stat(path, &st))

		return (0);

	if (st.st_mode & S_IFREG)
	{

		return (1);

	}	return (0);

}

/**
 * dupch -> A function to character with duplicate
 *@pst: It's a PATH is str
 *@start: It's a begin index
 *@stop: It's a stop index
 *Return: The point to new file
 */

char *dupch(char *pst, int start, int stop)
{
	static char buf[1024];
	int x = 0, z = 0;

	for (z = 0, x = start; x < stop; x++)

		if (pst[x] != ':')

			buf[z++] = pst[x];

	buf[z] = 0;

	return (buf);

}

/**
 * strpath -> A function that PATH str identifies command
 *@info: It's a data structure
 *@pst: It's a PATH is str
 *@cmd: It's a command to use
 *Return: The complete path of command || (NULL)
 */

char *strpath(info_t *info, char *pst, char *cmd)
{
	int x, cupo = 0;
	char *path;

	if (!pst)
		return (NULL);

	if ((lenstr(cmd) > 2) && nestart(cmd, "./"))
	{
		if (execomd(info, cmd))
			return (cmd);
	}

	for (x = 0; ; x++)
	{
		if (!pst[x] || pst[x] == ':')
		{
			path = dupch(pst, cupo, x);

			if (!*path)
				stdest(path, cmd);
			else
			{
				stdest(path, "/");
				stdest(path, cmd);
			}

			if (execomd(info, path))
				return (path);

			if (!pst[x])
			{
				break;
			}			cupo = x;
		}
	}	return (NULL);
}
