#include "main.h"

/**
 * _strcmps - compare two strings to find out if they are exactly the same.
 * @name: names supplied by user to search
 * @var: variables to compare againsts
 * @len: length of name
 *
 * Return: 1 if strings are == and -1 if they are not
 */

int _strcmps(char *name, char *var, unsigned int len)
{
	unsigned int var_len;
	unsigned int a;

	var_len = _strlens(var);
	if (var_len != len)
		return (-1);

	a = 0;
	while (name[a] != '\0' && var[a] != '\0')
	{
		if (name[a] != var[a])
			return (1);
		a++;
	}
	return (0);
}

/**
 * _strncmps - compares two strings
 * up to given lengths the same
 * @name: names that are supplied by user so to search for
 * @var: var to compare against
 * @len: leng to compare up to
 *
 * Return: 1 if strings are == and -1 if they are not
 */

int _strncmps(char *name, char *var, unsigned int len)
{
	unsigned int a;

	a = 0;
	while (a < len)
	{
		if (name[a] != var[a])
			return (-1);
		a++;
	}
	return (1);
}

/**
 * *_strcpy - copy strings pointed to by src to the buffer pointed to dest
 * @dest: the  string destination
 * @src: the string source
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int a;
	int i = _strlens(src);

	for (a = 0; a <= i; a++)
		dest[a] = src[a];

	return (dest);
}
/**
 * _strlens - return the length of string
 * @s: string that has to be evaluated
 *
 * Return: len of string
 */

int _strlens(char *s)
{
	int a = 0;

	while (s[a] != '\0')
		a++;

	return (a);
}
