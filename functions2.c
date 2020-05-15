#include "monty.h"

/**
 * _add - add two numbers from the top of that stack
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(ERROR_ADD);

	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * _nop - does not print, do not pass go, do not collect $200
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - subtracts the top element of the stack from the second top
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(ERROR_SUB);

	difference = (*stack)->next->n - (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = difference;
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(ERROR_DIV);

	if ((*stack)->n == 0)
		handle_errors(ERROR_DIV_ZERO);

	quotient = (*stack)->next->n / (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = quotient;
}

/**
 * _mul - multiplies the second top element of the stack with the top
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(ERROR_MUL);

	product = (*stack)->next->n * (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = product;
}
