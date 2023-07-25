#include "shell.h"

/**
 * nullify - Frees memory and sets the pointer to NULL.
 * @ptr: Pointer to the pointer to be freed.
 *
 * Return: 1 if successful, 0 if the pointer was already NULL.
 */
int nullify(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

