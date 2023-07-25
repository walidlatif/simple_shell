#include "shell.h"

/**
 * _strncpy - concatenates two strings.
 * @dest: string passed
 * @src: string passed
 * @n: int passed
 *
 * Return: dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
	return (dest);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *
 * Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[i] != '\0' && j < n)
	{
		dest[i] = src[i];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * *_strchr - locates a character in a string.
 *
 * @s: A pointer to the string to be searched.
 *
 * @c: The character to be located.
 *
 * Return: res
 */

char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
