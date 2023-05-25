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
