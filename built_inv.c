#include "monty.h"

/**
 * build_inventory - builds global struct of most used variables
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int build_inventory(void)
{
	inventory = malloc(sizeof(inventory_t));
	if (!inventory)
		handle_errors(ERROR_MALLOC);

	inventory->input = malloc(sizeof(char *) * 3);
	if (!inventory->input)
	{
		free(inventory);
		handle_errors(ERROR_MALLOC);
	}

	inventory->stack = NULL;
	inventory->line = NULL;
	inventory->linenum = 0;

	return (EXIT_SUCCESS);
}
