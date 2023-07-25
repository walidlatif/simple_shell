#include "shell.h"

/**
* _strcpy - copies string from src to dest
* @dest: where string will go
* @src: where string is from
*
* Return: returns string
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Function returns a pointer to a new allocated space in memory.
 * @str: A string.
 *
 * Return: A pointer of an array of chars.
 */
char *_strdup(const char *str)
{
	char *strout;
	unsigned int a, b;

	if (str == NULL)
		return (NULL);

	for (a = 0; str[a] != '\0'; a++)
		;

	strout = (char *)malloc(sizeof(char) * (a + 1));

	if (strout == NULL)
		return (NULL);

	for (b = 0; b <= a; b++)
		strout[b] = str[b];

	return (strout);
}
