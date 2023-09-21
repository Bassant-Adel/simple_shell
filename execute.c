#include "shell.h"

/**
 * hsh -> A function to main general
 *@info: It's an information struct
 *@av: It's a arg main
 *Return: (1) -> triumphs || (0) -> mistakes || -> (ERROR)
 */

int hsh(info_t *info, char **av)
{
	ssize_t h = 0;
	int builret = 0;

	while (h != -1 && builret != -2)
	{
		infostab(info);

		if (active(info))
		{
			pristr("$ ");
		}	addlett(BUF_FLUSH);
		h = remneli(info);

		if (h != -1)
		{
			setinfo(info, av);
			builret = filocbuil(info);

			if (builret == -1)
				findcomm(info);
		}
		else if (active(info))
		{
			prichar('\n');
		}		inforel(info, 0);
	}	writehis(info);
	inforel(info, 1);

	if (!active(info) && info->status)
		exit(info->status);
	if (builret == -2)
	{
		if (info->err_num == -1)
		{
			exit(info->status);
		}	exit(info->err_num);
	}	return (builret);
}

/**
 * filocbuil -> A function to identifier built-in command
 *@info: It's an information struct
 *Return: (-1) -> cannot be discovered || (0) -> successfully
 */

int filocbuil(info_t *info)
{
	int b, ballre = -1;
	biltin_tale bulttl[] = {
		{"exit", exitshell},
		{"env", prienv},
		{"help", prochdir},
		{"history", rhistory},
		{"setenv", envsset},
		{"unsetenv", envunsset},
		{"cd", chcudir},
		{"alias", halias},
		{NULL, NULL}
	};

	for (b = 0; bulttl[b].type; b++)

		if (comstr(info->argv[0], bulttl[b].type) == 0)
		{
			info->line_count++;
			ballre = bulttl[b].func(info);
			break;
		}

	return (ballre);
}

/**
 * findcomm -> A function to search for command -> PATH
 *@info: It's an information struct
 *Return: VOID
 */

void findcomm(info_t *info)
{
	char *path = NULL;
	int x, z;

	info->path = info->argv[0];

	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}

	for (x = 0, z = 0; info->arg[x]; x++)
		if (!ist_de(info->arg[x], " \t\n"))
			z++;
	if (!z)
		return;

	path = strpath(info, geetenv(info, "PATH="), info->argv[0]);

	if (path)
	{
		info->path = path;
		forkcomm(info);
	}
	else
	{
		if ((active(info) || geetenv(info, "PATH=")
					|| info->argv[0][0] == '/') && execomd(info, info->argv[0]))
			forkcomm(info);

		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			erroprint(info, "not found\n");
		}
	}
}

/**
 * forkcomm -> A function to run cmd after fork exec
 *@info: It's an information struct
 *Return: VOID
 */

void forkcomm(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, cpenviron(info)) == -1)
		{
			inforel(info, 1);

			if (errno == EACCES)
			{
				exit(126);
			}			exit(1);
		}
	}
	else
	{
		wait(&(info->status));

		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);

			if (info->status == 126)
				erroprint(info, "Permission denied\n");
		}
	}
}
