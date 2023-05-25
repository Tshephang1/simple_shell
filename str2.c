#include "main.h"

/**
 * strdup - duplicate string in the heap memory
 * @s: character pointer string
 *
 * Return: the duplicate string
 */
char *strdup(const char *s)
{
	char *newer;
	size_t length;

	len = _strlen(s);
	newer = malloc(sizeof(char) * (length + 1));
	if (newer == NULL)
		return (NULL);
	_memcpy(newer, s, length + 1);
	return (newer);
}

/**
 * strlen - returns len of string
 * @s: type character pointer
 *
 * Return: 0
 */

int strlen(const char *s)
{
	int length;

	for (length = 0; s[length] != 0; length++)
	return (length);
}

/**
 * cmp_char - compare characters of a string
 * @str: an input string
 * @del: delimiter
 *
 * Return: 1 if equal and 0 if not the case
 */

int cmp_char(char str[], const char *del)
{
	unsigned int a, n, i;

	for (a = 0, i = 0; str[a]; a++)
	{
		for (n = 0; del[j]; n++)
		{
			if (str[a] == del[n])
			{
				i++;
				break;
			}
		}
	}
	if (a == i)
		return (1);
	return (0);
}

/**
 * strtok - split string by some delimiter
 * @str: an input string
 * @del: delimiter
 *
 * Return: a string splited
 */

char *strtok(char str[], const char *del)
{
	static char *_splitted, *str_final;
	char *str_first;
	unsigned int a, bool;

	if (str != NULL)
	{
		if (cmp_char(str, del))
			return (NULL);
		_splitted = str;
		i = strlen(str);
		str_final = &str[a];
	}
	str_first = _splitted;
	if (str_first == str_final)
		return (NULL);

	for (bool = 0; *_splitted; _splitted++)
	{
		if (_splitted != str_first)
			if (*_splitted && *(_splitted - 1) == '\0')
				break;
		for (a = 0; del[a]; a++)
		{
			if (*_splitted == del[a])
			{
				*_splitted = '\0';
				if (_splitted == str_first)
					str_first++;
				break;
			}
		}
		if (bool == 0 && *_splitted)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_first);
}

/**
 * isdigit - define whether the string passed is a number
 * @s: the input string
 *
 * Return: 1 if string is number and 0 if not
 */

int isdigit(const char *s)
{
	unsigned int a;

	for (a = 0; s[a]; a++)
	{
		if (s[a] < 48 || s[a] > 57)
			return (0);
	}
	return (1);
}
