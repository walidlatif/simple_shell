#include "shell.h"

/**
 * **strtow - splits a string into words. using a spac
 * @str: the input array of characters and strings
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (!str || str[0] == '\0')
		return (NULL);
	if (!d)
		d = " ";

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;
	}
	if (numwords == 0)
		return (NULL);
	s = (char **)malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = (char *)malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = '\0';
	}
	s[j] = NULL;
	return (s);
}

/**
 * get_word_length - Calculate the length of a word in a string.
 * @str: The input string.
 * @d: The delimiter character.
 * @index: The current index in the string to start counting the word from.
 *
 * Return: The length of the word.
 */
static int get_word_length(char *str, char d, int index)
{
	int length = 0;

	while (str[index + length] != d && str[index + length] != '\0')
		length++;

	return (length);
}

/**
 * strtow2 - Split a string into an array of words using a delimiter.
 * @str: The input string to be split.
 * @d: The delimiter character.
 *
 * Return: An array of strings (words) or NULL on failure.
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	}
	if (numwords == 0)
		return (NULL);
	s = (char **)malloc((numwords + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != '\0')
			i++;
		k = get_word_length(str, d, i);
		s[j] = (char *)malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = '\0';
	}
	s[j] = NULL;
	return (s);
}

