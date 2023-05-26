#include "main.h"

/**
 * main - main loop of the shell
 *
 * Return: 0 success
 */

int main(void)
{
	char *_line, *_path, *_fullpath;
	char **_tokens;
	int _flag, _builtin_status, _child_status;
	struct stat buf;

	while (TRUE)
	{
		prompts(STDIN_FILENO, buf);
		_line = _getline(stdin);
		if (_strcmps(_line, "\n", 1) == 0)
		{
			free(_line);
			continue;
		}
		_tokens = conference(_line);
		if (_tokens[0] == NULL)
			continue;
		_builtin_status = builtinexecs(_tokens);
		if (_builtin_status == 0 || _builtin_status == -1)
		{
			free(_tokens);
			free(_line);
		}
		if (_builtin_status == 0)
			continue;
		if (_builtin_status == -1)
			_exit(EXIT_SUCCESS);
		_flag = 0; /* 0 if fullpath is not malloc'd */
		_path = getenviron("PATH");
		_fullpath = _which(_tokens[0], _fullpath, _path);
		if (_fullpath == NULL)
			_fullpath = _tokens[0];
		else
			_flag = 1; /* if full__path was malloc'd, flag to free */
		_child_status = tshephang(_fullpath, _tokens);
		if (_child_status == -1)
			error(2);

		free_all(_tokens, _path, _line, _fullpath, _flag);
	}

	return (0);
}
