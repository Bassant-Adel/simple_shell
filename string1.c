#include "shell.h"

/**
 * exitshell -> A function to exit shell
 *@info: It's a structure containing (arg)
 *Return: Exit with specified -> (exit)
 */

int exitshell(info_t *info)
{
	int execs;

	if (info->argv[1])
	{
		execs = intostr(info->argv[1]);

		if (execs == -1)
		{
			info->status = 2;
			erroprint(info, "Illegal number: ");

			strpo(info->argv[1]);
			addlett('\n');

			return (1);

		}		info->err_num = intostr(info->argv[1]);

		return (-2);

}
info->err_num = -1;
return (-2);
}

/**
 * chcudir -> A function to change current dir of process
 *@info: It's a structure containing arg
 *Return: (0)-> Successful
 */

int chcudir(info_t *info)
{
	char *x, *doo, buffs[1024];

	int rechdr;

	x = getcwd(buffs, 1024);

	if (!x)
		pristr("TODO: >>getcwd failure emsg here<<\n");

	if (!info->argv[1])
	{
		doo = getenv(info, "HOME=");
		if (!doo)
			rechdr = chdir((doo = getenv(info, "PWD=")) ? doo : "/");
		else
			rechdr = chdir(doo);
	}
	else if (comstr(info->argv[1], "-") == 0)
	{
		if (!getenv(info, "OLDPWD="))
		{
			pristr(x);
			prichar('\n');
			return (1);
		}		pristr(getenv(info, "OLDPWD=")), prichar('\n');
		rechdr = chdir((doo = getenv(info, "OLDPWD=")) ? doo : "/");
	}
	else
		rechdr = chdir(info->argv[1]);
	if (rechdr == -1)
	{
		erroprint(info, "can't cd to ");
		strpo(info->argv[1]), addlett('\n');
	}
	else
	{
		envinit(info, "OLDPWD", getenv(info, "PWD="));
		envinit(info, "PWD", getcwd(buffs, 1024));

	}	return (0);
}

/**
 * prochdir -> A function to change current dir of process
 *@info: It's a structure containing arg
 *Return: (0)-> Successful
 */

int prochdir(info_t *info)
{
	char **arrayg;

	arrayg = info->argv;

	pristr("help call works. Function not yet implemented \n");

	if (0)
	{

		pristr(*arrayg);

	}	return (0);

}
