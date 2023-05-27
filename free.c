#include "main.h"

/**
 * free_all - free mallocd spaces at end of main loop
 * @tokens: pointer to the tokens array
 * @paths: pointer to path variable.
 * @lines: pointer to the user input buffer
 * @fullpaths: pointer to the full path
 * @flags: flag marking when full_path was mallocd
 *
 * Return: void
 */

void free_all(char **tokens, char *paths, char *lines, char *fullpaths,
int flags)
{
	free(paths);
	free(tokens);
	free(lines);
	if (flags == 1)
		free(fullpaths);
}

/**
 * free_dps - free the double pointer
 * @arrays: double pointer to the free
 * @lengths: length of the double pointer
 *
 * Return: void
 */

void free_dps(char **arrays, unsigned int lengths)
{
	unsigned int a;

	a = 0;
	while (a < lengths)
	{
		free(arrays[a]);
		a++;
	}
	free(arrays);
}
