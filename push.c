#include "push_swap.h"
#include <stdio.h>

/*
	Take the first element at the top of a stack
	Do nothing the stack is empty
*/

static t_list	*remove_stack(t_list **stack)
{
	t_list	*removed;

	removed = *stack;
	if (removed == NULL)
		return (NULL);
	if (removed->next == removed)
	{
		*stack = NULL;
		removed->next = NULL;
		removed->prev = NULL;
		return (removed);
	}
	else
	{
		removed->next->prev = removed->prev;
		removed->prev->next = removed->next;
		*stack = removed->next;
		removed->next = NULL;
		removed->prev = NULL;
		return (removed);
	}
}

static t_list	*add_stack(t_list *stack, t_list **to)
{
	t_list	*current;
	t_list	*last;

	current = *to;
	if (current == NULL)
	{
		stack->next = stack;
		stack->prev = stack;
		*to = stack;
		return (stack);
	}
	else
	{
		last = current->prev;
		stack->next = current;
		stack->prev = last;
		current->prev = stack;
		last->next = stack;
		*to = stack;
		return (*to);
	}
}

void	push(t_list **from, t_list **to)
{
	t_list	*stack;

	stack = remove_stack(from);
	if (stack)
		*to = add_stack(stack, to);
}

void	do_pa(t_list **a_stack, t_list **b_stack)
{
	push(b_stack, a_stack);
	ft_putendl_fd("pa", 1);
}

void	do_pb(t_list **a_stack, t_list **b_stack)
{
	push(a_stack, b_stack);
	ft_putendl_fd("pb", 1);
}
