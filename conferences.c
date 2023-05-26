#include "main.h"

/**
 * conference - conference a string
 * @str: user input
 *
 * Return: pointer array of tokens
 */

char **conference(char *str)
{
	char **_tokens;
	char *_token;
	unsigned int a;

	_tokens = malloc(sizeof(char) * BUFFER);
	if (_tokens == NULL)
	{
		error(3);
		exit(EXIT_FAILURE);
	}

	_token = strtok(str, "\n\t\r ");

	a = 0;
	while (_token != NULL)
	{
		_tokens[a] = _token;
		_token = strtok(NULL, "\n\t\r ");
		a++;
	}

	_tokens[a] = NULL;

	return (_tokens);
}
