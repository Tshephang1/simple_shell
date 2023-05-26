#include "main.h"

/**
* shell_exits - exit the shell
*
* Return: void
**/

int shell_exits(void)
	{
		return (-1);
	}


/**
* shell_environ - print the  environment
*
* Return: void
**/

int shell_environ(void)
{
		unsigned int a;

		a = 0;
		while (_environ[a] != NULL)
		{
			write(STDOUT_FILENO, _environ[a], _strlens(_environ[a]));
			write(STDOUT_FILENO, "\n", 1);
			a++;
		}
		return (0);
}
