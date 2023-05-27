#include "main.h"

/**
 * _getline - put inputs from user into buff line
 * @fp: buf for user input
 *
 * Return: buffer with a user input
 */

char *_getline(FILE *fp)
{
	char *_line;
	ssize_t _read;
	size_t _len;

	_line = NULL;
	_len = 0;
	_read = getline(&_line, &_len, fp);
	if (_read == -1)
	{
		free(_line);
		exit(EXIT_SUCCESS);
	}

	return (_line);
}
