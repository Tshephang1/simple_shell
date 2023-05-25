#include "main.h"

/**
 * err_env - error message for env in get_env.
 * @datashell: data relevant (counter, arguments)
 * Return: Error message
 */

char *err_env(data_shell *datashell)
{
	int len;
	char *err;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datashell->counter);
	msg = ": Unable to add/remove from environment\n";
	len = _strlen(datashell->av[0]) + _strlen(ver_str);
	len += _strlen(datashell->args[0]) + _strlen(msg) + 4;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}

	_strcpy(err, datashell->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datashell->args[0]);
	_strcat(err, msg);
	_strcat(err, "\0");
	free(ver_str);

	return (err);
}
/**
 * err_path_126 - error message for path and failure denied permission.
 * @datashell: data relevant (counter, arguments).
 *
 * Return: error string
 */

char *err_path_126(data_shell *datashell)
{
	int len;
	char *ver_str;
	char *err;

	ver_str = aux_itoa(datashell->counter);
	len = _strlen(datashell->av[0]) + _strlen(ver_str);
	len += _strlen(datashell->args[0]) + 24;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datashell->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datashell->args[0]);
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}
