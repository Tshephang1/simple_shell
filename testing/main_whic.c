#include "main.h"

/**
 * main - print full path that given command
 *
 * Return: 0.
 */

int main(void)
{
	char *fullpath = NULL;

	fullpath = _which("ls", fullpath);
	printf("Path: %s\n", fullpath);
	free(fullpath);

	return (0);
}
