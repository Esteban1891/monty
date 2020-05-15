#include "monty.h"

/**
 * _mod - computes the rest of the division of the second top element of the
 *        stack by the top element of the stack.
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int modulo;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(ERROR_MOD);

	if ((*stack)->n == 0)
		handle_errors(ERROR_DIV_ZERO);

	modulo = (*stack)->next->n % (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = modulo;
}

/**
 * _pchar - prints the char type of the head node integer
 * @stack: the stack
 * @line_number: line number
 *
 * Return: None
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!stack || !*stack)
		handle_errors(ERROR_STACK_EMPTY);

	if ((*stack)->n < 0 || (*stack)->n > 127)
		handle_errors(ERROR_PCHAR_RANGE);

	printf("%c\n", (*stack)->n);
}
