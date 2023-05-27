#include "main.h"

/**
 * _which - search directory in PATH variable for command
 * @_command: command to search for
 * @fullpath: the fullpath of command to execute
 * @_path: full path variable
 *
 * Return: pointer to fullpath
 */

char *_which(char *_command, char *fullpath, char *_path)
{
	unsigned int commandlength, pathlength, original_pathlength;
	char *pathcopy, *_token;

	commandlength = _strlens(_command);
	original_pathlength = _strlens(_path);
	pathcopy = malloc(sizeof(char) * original_pathlength + 1);
	if (pathcopy == NULL)
	{
		error(3);
		return (NULL);
	}
	_strcpy(pathcopy, _path);
	/* copy path directory plus command name and check if it exist */
	_token = strtok(pathcopy, ":");
	if (_token == NULL)
		_token = strtok(NULL, ":");
	while (_token != NULL)
	{
		pathlength = _strlens(_token);
		fullpath = malloc(sizeof(char) * (pathlength + commandlength) + 2);
		if (fullpath == NULL)
		{
			error(3);
			return (NULL);
		}
		_strcpy(fullpath, _token);
		fullpath[pathlength] = '/';
		_strcpy(fullpath + pathlength + 1, _command);
		fullpath[pathlength + commandlength + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			_token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(pathcopy);

	return (fullpath);
}
