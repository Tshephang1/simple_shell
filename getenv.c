#include "main.h"

/**
 * getenviron - get an environment variable
 * @name: the environment variable to get
 *
 * Return: pointer to environment variables or NULL if there is not matched
 */

char *getenviron(const char *name)
{
	char **environcopy;
	char *_variable, *_value, *_path;
	int _compare;
	unsigned int pathlength, environlength, _length, a;

	environlength = 0;
	while (_environ[environlength] != NULL)
		environlength++;
	environcopy = NULL;
	environcopy = copyenv(environcopy, environlength);

	_length = _strlens((char *)name);
	a = 0;
	while (environcopy[a] != NULL)
	{
		_variable = environcopy[a];
		_compare = _strncmps((char *)name, _variable, _length);
		if (_compare == 1)
		{
			_value = strtok(_variable, "=");
			_value = strtok(NULL, "\n ");
			if (*_value == '\0')
			{
				error(4);
				exit(EXIT_FAILURE);
			}
			pathlength = _strlens(_value);
			_path = malloc(sizeof(char) * pathlength + 1);
			if (_path == NULL)
			{
				error(3);
				return (NULL);
			}
			_path = _strcpy(_path, _value);
			free_dps(environcopy, environlength);
			return (_path);
		}
		a++;
	}

	return (NULL);
}

/**
 * copyenv - copy the environment variable
 * @environcopy: pointer to copy of the  environment variable
 * @environlength: length of the environment variable
 *
 * Return: double pointer to copy of the environment variable
 */

char **copyenv(char **environcopy, unsigned int environlength)
{
	char *_variable;
	unsigned int variablelength;
	unsigned int a;

	environcopy = malloc(sizeof(char **) * (environlength));
	if (environcopy == NULL)
	{
		error(3);
		return (NULL);
	}

	a = 0;
	while (a < environlength)
	{
		_variable = _environ[a];
		variablelength = _strlens(_variable);

		environcopy[a] = malloc(sizeof(char) * variablelength + 1);
		if (environcopy[a] == NULL)
		{
			error(3);
			return (NULL);
		}
		_strcpy(environcopy[a], _environ[a]);
		a++;
	}
	return (environcopy);
}
