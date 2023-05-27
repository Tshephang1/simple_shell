#include "main.h"

/**
* builtinexecs - executes the built ins functions
* @_tokens: arguments to be passed
* Return: tokens
**/

int builtinexecs(char **_tokens)
{
	int _status;
	unsigned int _length;
	unsigned int _num;
	unsigned int a;

	built_s builtins[] = {
		{"exit", shell_exits},
		{"env", shell_environ},
		{NULL, NULL}
	};

	if (_tokens[0] == NULL)
		return (1);

	_length = _strlens(_tokens[0]);

	_num = shell_num_builtins(builtins);
	for (a = 0; a < _num; a++)
	{
		if (_strcmps(_tokens[0], builtins[a].name, _length) == 0)
		{
			_status = (builtins[a].p)();
			return (_status);
		}
	}

	return (1);
}

/**
* shell_num_builtins - this checks num builtins
* @builtin: take the builtin to be counted.
*
* Return: number of builtins
**/

int shell_num_builtins(built_s builtins[])
{
	unsigned int a;

	a = 0;
	while (builtins[a].name != NULL)
		a++;
	return (a);
}
