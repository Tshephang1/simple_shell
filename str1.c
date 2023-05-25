#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: character pointer, the dest of the copied string
 * @src: constant character pointer, the source of str
 * Return: dest
 */

char *_strcat(char *dest, const char *sc)
{
	int a;
	int n;

	for (a = 0; dest[a] != '\0'; a++);

	for (n = 0; sc[n] != '\0'; n++)
	{
		dest[a] = sc[n];
		a++;
	}

	dest[a] = '\0';
	return (dest);
}

/**
 * *_strcpy - copies the strinsg pointed to src
 * @dest: character pointer, dest of the copied string
 * @sc: character pointer, source of string
 *
 * Return: dest
 */

char *_strcpy(char *dest, char *sc)
{

	size_t i;

	for (i = 0; sc[i] != '\0'; i++)
	{
		dest[i] = sc[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - a function that compares two strings
 * @s1: string compared 1
 * @s2: string compared 2
 *
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] == s2[a] && s1[a]; a++);

	if (s1[a] > s2[a])
		return (1);

	if (s1[a] < s2[a])
		return (-1);

	return (0);
}

/**
 * _strchr - locate character in a string
 * @s: a string
 * @c: a character
 *
 * Return: pointer tofirst occurrence of the character c
 */

char *_strchr(char *s, char c)
{
	unsigned int a = 0;

	for (; *(s + a) != '\0'; a++)
		if (*(s + a) == c)
			return (s + a);
	if (*(s + a) == c)
		return (s + a);

	return ('\0');
}

/**
 * _strspn - get the length of prefix substringl
 * @s: segment
 * @accpt: accepted byte
 *
 * Return: number of accepted bytes
 */

int _strspn(char *s, char *accpt)
{
	int a, n, bool;

	for (a = 0; *(s + a) != '\0'; a++)
	{
		bool = 1;
		for (n = 0; *(accpt + n) != '\0'; n++)
		{
			if (*(s + a) == *(accpt + n))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (a);
}
