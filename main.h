#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"


         /* Our error1.c */
char *strcat_ct(data_shell *, char *, char *, char *);
char *err_get_ct(data_shell *datashell);
char *err_not_found(data_shell *datashell);
char *err_exit_shell(data_shell *datashell);


       /* Our error2.c */
char *err_get_alias(char **args);
char *err_env(data_shell *datashell);
char *err_syntax(char **args);
char *err_permission(char **args);
char *err_path_126(data_shell *datashell);

     /* Our help.c */
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_general(void);
void help_exit(void);

   /* Our help2.c */
void help(void);
void help_alias(void);
void help_cd(void);


    /* Our lists.c */
se_list *add_se_node_end(se_list **head, char se);
void free_se_list(se_list **head);
line_lists *add_line_nod_end(line_lists **head, char *line);
void free_line_lists(line_lists **head);

      /* Our lists2.c */
r_vars *add_rvars_node(r_vars **head, int lvars, char *vars, int lvals);
void free_rvars_list(r_vars **head);


        /* Our mememory.c */
void _memcpy(void *nptr, const void *ptr, unsigned int siz);
void *_reallocs(void *ptr, unsigned int old_siz, unsigned int new_siz);
char **_reallocdps(char **ptr, unsigned int old_siz, unsigned int new_siz);


  /* Our stdlib.c */
int get_len(int n);
char *itoi(int n);
int _atoi(char *s);

    /* Our str1.c  */
char *_strcat(char *dest, const char *sc);
char *_strcpy(char *dest, char *sc);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strspn(char *s, char *accpt);

   /* Our str2.c */
char *strdup(const char *s);
int strlen(const char *s);
int cmp_char(char str[], const char *del);
char *strtok(char str[], const char *del);
int isdigit(const char *s);


/* Our str3.c */
void rev_strings(char *s);
