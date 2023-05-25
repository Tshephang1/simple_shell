#include "main.h"

/**
 * help_env - Help info for the builtin env
 *
 * Return: NO return
 */

void help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Print the enviroment of shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));

}

/**
 * help_setenv - Help info for the builtin setenv
 *
 * Return: NO return
 */

void help_setenv(void)
{
	char *help = "setenv: setenv (const char *name, const char *value, ";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "int replaces)\n\t";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Add new definition to environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * help_unsetenv - Help info for the builtin unsetenv
 *
 * Return: NO return
 */

void help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Remove an entry completely from environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}


/**
 * help_general - Entry point for help information for the help builtin
 *
 * Return: NO return
 */

void help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "These commands are defined only internally.Type 'help' to see the lists";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about functions 'name'.\n\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = " alias: alias [name=['strings']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[dir]\nexit: exit [n] \n  env: env [options] [name=value] [command ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[args]]\n  setenv: setenv [variables] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "unsetenv [variables]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * help_exit - Help info for the builint exit
 *
 * Return: NO return
 */

void help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "status is that of last command executed\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
