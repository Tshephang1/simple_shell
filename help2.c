#include "main.h"

/**
 * help - Help info for the builtin help
 *
 * Return: NO return
 */

void help(void)
{
	char *help = "help: help [-dms] [pattern ..]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin command.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin command.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * help_alias - Help info for the builtin alias
 *
 * Return: NO return
 */

void help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]..]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefines or displays aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * help_cd - Help info for the builtin alias
 *
 * Return: NO return
 */

void help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n ";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
