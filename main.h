#ifndef ANDY_H
#define ANDY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "
/* error strings */
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"

extern char **_environ;

/**
 * struct list_s - linked list of variables
 * @value: value
 * @next: pointer to next node
 *
 * Description: generic linked list struct for variables.
**/

typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
 * Description: struct for builtin functions.
**/

typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

void prompts(int fd, struct stat buf);
char *_getline(FILE *fp);
char **conference(char *str);
char *_which(char *command, char *fullpath, char *path);
int tshephang(char *fullpath, char **_tokens);
void error(int error);

      /* free functions */
void free_all(char **tokens, char *paths, char *lines, char *fullpaths, int flags);
void free_dps(char **arrays, unsigned int lengths);

  /* utility functions */
void _puts(char *str);
int _strlens(char *s);
int _strcmps(char *name, char *var, unsigned int len);
int _strncmps(char *name, char *var, unsigned int len);
char *_strcpy(char *dest, char *src);


   /* prototypes for the helper functions for path linked list */
char *getenviron(const char *name);
char **copyenv(char **_environcopy, unsigned int _environlength);
list_s *pathlists(char *_variable, list_s *head);


   /* prototypes for builtins */
int shell_environ(void);
int shell_exits(void);
int builtinexecs(char **tokens);
int shell_num_builtins(built_s builtins[]);


#endif 
