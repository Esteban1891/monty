#include "monty.h"

/**
 * main - main function for monty program
 * @argc: arguments count
 * @argv: arguments inventory (file path expected)
 *
 * Return: 0 always - success!
 */
int main(int argc, char **argv)
{
	size_t n;
	void (*execute)(stack_t **stack, unsigned int line_number);

	inventory = NULL;
	if (argc != 2)
		handle_errors(ERROR_USAGE_FILE);

	build_inventory();
	inventory->filename = argv[1];
	inventory->file = fopen(inventory->filename, "r");

	if (inventory->file == NULL)
		handle_errors(ERROR_OPEN_FILE);

	while (getline(&inventory->line, &n, inventory->file) > 0)
	{
		inventory->linenum++;

		if (parse_line(inventory->line) == EXIT_FAILURE)
			continue;

		execute = match_opcode();
		execute(&inventory->stack, inventory->linenum);
	}
	free_all();
	return (EXIT_SUCCESS);
}
