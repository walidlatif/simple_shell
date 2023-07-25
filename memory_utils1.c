#include "shell.h"

/**
* _strlen - returns the length of a string
*
* @s: string passed
*
* Return: returns length of string passed
*/

int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

/**
 * _strcmp - compares two strings.
 * @s2: string passed
 * @s1: string passed
 *
 * Return: i (result).
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, j;

	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	j = s1[i] - s2[i];
	return (j);
}

/**
 * _strcat - concatenates two strings.
 * @dest: string passed
 * @src: string passed
 *
 * Return: dest.
 */

char *_strcat(char *dest, char *src)
{
	int j, i;

	i = 0;

	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
