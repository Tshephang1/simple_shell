#include "main.h"

/**
 * tshephang - a function for child process
 * @_fullpath: full path of executable
 * @_tokens: tokenized user inputs
 *
 * Return: 0 on succes
 */

int tshephang(char *_fullpath, char **_tokens)
{
	pid_t _child_pid;
	int _status;
	int _execve_status;
	char **_envp = _environ;

	_child_pid = fork();
	if (_child_pid == -1)
	{
		error(1);
		exit(EXIT_FAILURE);
	}
	if (_child_pid == 0)
	{
		_execve_status = execve(_fullpath, _tokens, _envp);
		if (_execve_status == -1)

			return (-1);
	}
	else
		wait(&_status);

	return (0);
}
