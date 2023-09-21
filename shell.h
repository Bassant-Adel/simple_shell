#ifndef SHELL_H
#define SHELL_H


/* **The C Standard Library** */


#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>


/* **The C Macro Definition Documentation** */


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

#define BUF_FLUSH -1
#define CMD_NORM	0

#define CMD_OR		1
#define CMD_AND		2

#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1

#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0

#define USE_STRTOK 0
#define HIST_FILE	".simple_shell_history"

#define HIST_MAX	4096
#define NOT_FOUND 127

#define PERMISSION_DENIED 126

extern char **environ;

extern char *getenv(const char *name);

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}


/* Typedefs  */


/**
 * struct liststr -> singly linked list
 *@num: It's a num field
 *@str: It's a string
 *@next: points to the next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo -> contains fictitious arguments used to call
 *allowing a consistent prototype for function pointer structs
 *@arg: a string produced by getline that contains arguments
 *@argv: a collection of strings created from arg
 *@path: a string representing the current command's path
 *@argc: argument count
 *@line_count: the number of errors
 *@err_num: the exit() error code
 *@linecount_flag: if this line of input counts,
 *@fname: program filename
 *@env: localised linked list copy of environ
 *@environ: LL env environment modified specifically
 *@history: historical node
 *@alias: alias node
 *@env_changed: if the environment had changed.
 *@status: the last command that was executed's return status
 *@cmd_buf: address of the cmd_buf pointer, if chaining
 *@cmd_buf_type: Command-type ||, &&, ;
 *@readfd: the fd to read line input from
 *@histcount: the number of lines in history
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;

	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;

	list_t *env;
	list_t *history;
	list_t *alias;

	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;


/**
 * struct builtin -> A function to contain builtin str & related
 *@type: It's a builtin command flag
 *@func: It's a function
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} biltin_tale;



/* **All Prototypes** */

int alphaa(int c);
int intfs(char *s);
int prichar(char c);
int lenstr(char *s);
int addlett(char c);
int intostr(char *s);
void strpo(char *str);
void relst(char **pp);
void pristr(char *str);
int active(info_t *info);
int halias(info_t *info);
int freeaddr(void **ptr);
int prienv(info_t *info);
int hisrem(info_t *info);
int chcudir(info_t *info);
int envfill(info_t *info);
int envsset(info_t *info);
int readhis(info_t *info);
int prochdir(info_t *info);
int rhistory(info_t *info);
int writehis(info_t *info);
int fdlett(char c, int fd);
void replacecom(char *buf);
void findcomm(info_t *info);
int bvreplace(info_t *info);
int filocbuil(info_t *info);
char *gethisf(info_t *info);
int exitshell(info_t *info);
int envunsset(info_t *info);
int paliasstr(list_t *node);
void infostab(info_t *info);
void forkcomm(info_t *info);
int stipri(char *str, int fd);
char **strtlist(list_t *head);
size_t plist(const list_t *h);
char *dupstr(const char *str);
ssize_t remneli(info_t *info);
int ist_de(char c, char *deli);
char **cpenviron(info_t *info);
char *fstrace(char *s, char c);
int aliasreplace(info_t *info);
int comstr(char *s1, char *s2);
size_t lenlist(const list_t *h);
void listfree(list_t **ptrhead);
size_t lenglis(const list_t *h);
int decprint(int input, int fd);
char **delstr(char *str, char d);
int hsh(info_t *info, char **av);
char **divstr(char *str, char *d);
char *stdest(char *dest, char *src);
char *strcop(char *dest, char *src);
int remenv(info_t *info, char *var);
void inforel(info_t *info, int all);
int replacestr(char **old, char *new);
int execomd(info_t *info, char *path);
void setinfo(info_t *info, char **av);
int alias_set(info_t *info, char *str);
int alias_unset(info_t *info, char *str);
void erroprint(info_t *info, char *estr);
char *copsr(char *dest, char *src, int n);
char *coptsr(char *dest, char *src, int n);
ssize_t retnode(list_t *head, list_t *node);
char *dupch(char *pst, int start, int stop);
char *geetenv(info_t *info, const char *name);
char *conmem(char *s, char b, unsigned int n);
int remnode(list_t **head, unsigned int index);
void sigan(__attribute__((unused))int sig_num);
int ischain(info_t *info, char *buf, size_t *p);
int envinit(info_t *info, char *var, char *value);
char *strpath(info_t *info, char *pst, char *cmd);
char *reconvert(long int num, int base, int flags);
int baddhl(info_t *info, char *buf, int linecount);
ssize_t reabuf(info_t *info, char *buf, size_t *v);
int gain(info_t *info, char **ptr, size_t *length);
list_t *prefnode(list_t *node, char *prefix, char c);
ssize_t inbuff(info_t *info, char **buf, size_t *len);
char *nestart(const char *haystack, const char *needle);
list_t *nodeadd(list_t **head, const char *str, int num);
list_t *addnodend(list_t **head, const char *str, int num);
void *relmem(void *ptr, unsigned int oldsi, unsigned int newsi);
void checkch(info_t *info, char *buf, size_t *p, size_t v, size_t len);


#endif
