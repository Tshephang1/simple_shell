#include "main.h"

/**
 * main - use strtok to print tokens
 * Return: success 0
 */

int main(void)
{
	char *_str = NULL;
	char **_tokens = NULL;
	unsigned int a;

	_str = _getline(stdin, _str);

	_tokens = _strtok(_str, _tokens);

	a = 0;
	while (_tokens[a] != NULL)
	{
		printf("%s\n", _tokens[a]);
		a++;
	}

	free(_str);
	free(_tokens);

	return (0);
}
