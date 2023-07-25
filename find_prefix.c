#include "shell.h"

/**
 * starts_with - Checks if the string needle is
 * a prefix of the string haystack.
 * @haystack: The string to search.
 * @needle:  The substring to find.
 *
 * Return: The address of the next character in haystack
 * after the prefix, or NULL if needle is not a prefix.
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle != *haystack)
			return (NULL);

		needle++;
		haystack++;
	}

	return ((char *)haystack);
}
