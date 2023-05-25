#include "main.h"

/**
 * get_len - get a len of a number
 *
 * @n: int num
 *
 * Return: lenght of number
 */

int get_len(int n)
{
	unsigned int _n;
	int len = 1;

	if (n < 0)
	{
		len++;
		_n = n * -1;
	}
	else
	{
		_n = n;
	}
	while (_n > 9)
	{
		len++;
		_n = _n / 10;
	}

	return (len);
}

/**
 * itoi - function convert int to string
 * @n: type int numb
 *
 * Return: a string
 */

char *itoi(int n)
{
	unsigned int _n;
	int len = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + len) = '\0';

	if (n < 0)
	{
		_n = n * -1;
		buffer[0] = '-';
	}
	else
	{
		_n = n;
	}

	len--;
	do {
		*(buffer + len) = (_n % 10) + '0';
		_n = _n / 10;
		len--;
	}
	while (_n > 0)
		;
	return (buffer);
}

/**
 * _atoi - convert a string to a integer
 * @s: input strings
 *
 * Return: int
 */

int _atoi(char *s)
{
	unsigned int _count = 0, siz = 0, _oi = 0, _pn = 1, _m = 1, a;

	while (*(s + _count) != '\0')
	{
		if (siz > 0 && (*(s + _count) < '0' || *(s + _count) > '9'))
			break;

		if (*(s + _count) == '-')
			_pn *= -1;

		if ((*(s + _count) >= '0') && (*(s + _count) <= '9'))
		{
			if (siz > 0)
				_m *= 10;
			siz++;
		}
		_count++;
	}

	for (a = _count - siz; a < _count; a++)
	{
		_oi = _oi + ((*(s + a) - 48) * _m);
		_m /= 10;
	}
	return (_oi * _pn);
}
