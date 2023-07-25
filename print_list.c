#include "shell.h"

/**
 * print_list - The function displays all elements
 * contained in a linked list of type list_t
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		if (h->str != NULL)
		{
			_puts(h->str);
		}
		else
		{
			_puts("(nil)");
		}
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
