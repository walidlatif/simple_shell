#include "shell.h"

/**
 * clear_info - Initializes the info_t struct by setting
 * its members to default values.
 * @info: Pointer to the info_t struct to be initialized.
 */

void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - Initializes the info_t struct with
 * the given argument vector.
 * @info: Pointer to the info_t struct to be initialized.
 * @av: Argument vector to set in the info_t struct.
 */

void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - Frees the fields of the info_t struct.
 * @info: Pointer to the info_t struct whose fields will be freed.
 * @all: True if all fields should be freed, otherwise
 * only necessary fields are freed.
 */

void free_info(info_t *info, int all)
{
	free_function(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		free_function(info->environ);
			info->environ = NULL;
		nullify((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
