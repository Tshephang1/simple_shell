#include "main.h"

/**
 * prompts - check the mode and prints prompt if in interactive mode
 * @fd: the file stream
 * @buff: buffer
**/

void prompts(int fd, struct stat buff)
{
	fstat(fd, &buff);

	if (S_ISCHR(buff.st_mode))
		_puts(PROMPT);
}

/**
 * _puts - print a string without a \n
 * @str: string to be printed
 *
 * Return: void
 */

void _puts(char *str)
{
	unsigned int len;

	len = _strlens(str);

	write(STDOUT_FILENO, str, len);
}
