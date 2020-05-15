#include "monty.h"

/**
 * _push - adds a new node at the beginning of a stack_t list
 * @stack: head of stack (linked list)
 * @line_number: line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *num;
	(void)line_number;

	if (inventory->input[1] == NULL)
		handle_errors(ERROR_PUSH);
	else
		num = inventory->input[1];

	if (are_digits(num) == TRUE)
	{
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
			handle_errors(ERROR_MALLOC);
	}
	else
		handle_errors(ERROR_PUSH);

	if (new_node)
	{
		new_node->n = atoi(num);
		new_node->prev = NULL;
		new_node->next = *stack;
		*stack = new_node;
	}
}

/**
 * _pall - prints all the elements from the stack
 * @stack: head of stack
 * @line_number: line number
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;
	size_t i;
	(void)line_number;

	for (i = 0; copy; i++, copy = copy->next)
	{
		if (copy != NULL)
			printf("%d\n", copy->n);
	}
}

/**
 * _pint - prints the number of the head node
 * @stack: the stack
 * @line_number: line number
 * Return: None
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!stack || !*stack)
		handle_errors(ERROR_PINT);

	printf("%d\n", (*stack)->n);
}

/**
 * _pop - pop the top element off the stack, i.e. remove head
 * @stack: head of stack (linked list)
 * @line_number: line number
 *
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;
	(void)line_number;

	if (*stack == NULL)
		handle_errors(ERROR_POP);
	else if ((*stack)->next != NULL)
	{
		next = (*stack)->next;
		next->prev = NULL;
		free(*stack);
		*stack = next;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * _swap - swap the top two elements
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		handle_errors(ERROR_SWAP);

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
