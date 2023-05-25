#include "main.h"

/**
 * strcat_ct - function tha concatenates the message for cd error
 *
 * @datashell: data relevant (directory)
 * @msg: message(s) to print
 * @err: output msg
 * @ver_str: our counter line
 * Return: error msg
 */

char *strcat_ct(data_shell *datashell, char *msg, char *err, char *ver_str)
{
	char *flag;

	_strcpy(err, datashell->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datashell->args[0]);
	_strcat(err, msg);
	if (datashell->args[1][0] == '-')
	{
		flag = malloc(3);
		flag[0] = '-';
		flag[1] = datashell->args[1][1];
		flag[2] = '\0';
		_strcat(err, flag);
		free(flag);
	}
	else
	{
		_strcat(err, datashell->args[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}

/**
 * err_get_ct - error message for cd command in get_ct
 * @datashell: our data relevant (directory)
 * Return: error messages
 */

char *err_get_ct(data_shell *datashell)
{
	int len, len_id;
	char *err, *ver_str, *msg;

	ver_str = aux_itoa(datashell->counter);
	if (datashell->args[1][0] == '-')
	{
		msg = ": unvalid option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't ct to ";
		len_id = _strlen(datashell->args[1]);
	}

	len = _strlen(datashell->av[0]) + _strlen(datashell->args[0]);
	len += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	err = malloc(sizeof(char) * (len + 1));

	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}

	err = strcat_ct(datashell, msg, err, ver_str);

	free(ver_str);

	return (err);
}

/**
 * err_not_found - generic error message for command not found
 * @datashell: data relevant (counter, arguments)
 * Return: error message
 */

char *err_not_found(data_shell *datashell)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(datashell->counter);
	len = _strlen(datashell->av[0]) + _strlen(ver_str);
	len += _strlen(datashell->args[0]) + 16;
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
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/**
 * err_exit_shell - generic error message for exit in get_exit
 * @datashell: data relevant (counter, arguments)
 *
 * Return: error message
 */

char *err_exit_shell(data_shell *datashell)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(datashell->counter);
	len = _strlen(datashell->av[0]) + _strlen(ver_str);
	len += _strlen(datashell->args[0]) + _strlen(datashell->args[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datashell->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datashell->args[0]);
	_strcat(err, ": unvalid number: ");
	_strcat(err, datashell->args[1]);
	_strcat(err, "\n\0");
	free(ver_str);

	return (err);
}
