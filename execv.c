# include "monty.h"

/**
 * match_opcode - function to handle opcodes and their paired functions
 *
 * Return: function needed
 */

void (*match_opcode(void))(stack_t **stack, unsigned int line_number)
{
	char *input_opcode;
	instruction_t *i;
	static instruction_t instructions[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL}
	};

	i = instructions;
	input_opcode = inventory->input[0];

	while (i->opcode && strncmp(i->opcode, input_opcode, strlen(input_opcode)))
		i++;

	if (!i->f)
		handle_errors(ERROR_UNKNOWN);

	return (i->f);
}

/**
 * parse_line - parses line/getline into input global variable
 * @line: input line
 *
 * Return: void
 */

int parse_line(char *line)
{
	char *delim, *s;
	int len, i;

	delim = " \t\n";
	s = inventory->line;
	len = strlen(s);

	for (i = 0; s[i] == delim[0] || s[i] == delim[1] || s[i] == delim[2]; i++)
		;
	if (i == len)
		return (EXIT_FAILURE);

	inventory->input[0] = strtok(line, delim);

	if (inventory->input[0][0] == '#')
		return (EXIT_FAILURE);

	inventory->input[1] = strtok(NULL, delim);

	return (EXIT_SUCCESS);
}
