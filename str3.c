#include "main.h"

/**
 * rev_strings - reverse a string
 * @s: an input string
 *
 * Return: NO return
 */

void rev_strings(char *s)
{
	int _count = 0, a, n;
	char *str, temps;

	while (_count >= 0)
	{
		if (s[_count] == '\0')
			break;
		_count++;
	}
	str = s;

	for (a = 0; a < (_count - 1); a++)
	{
		for (n = a + 1; n > 0; n--)
		{
			temps = *(str + n);
			*(str + n) = *(str + (n - 1));
			*(str + (n - 1)) = temps;
		}
	}
}
