#include "push_swap.h"

/*
	Take the first element at the top of a stack
	Do nothing the stack is empty
*/

static t_list	*remove_stack(t_list **stack)
{
	t_list *removed;

	removed = *stack;
	if (removed == NULL)
		return (NULL);
	if (removed->next)
		removed->next->prev = removed->prev;
	if (removed->prev)
		removed->prev->next = removed->next;
	if (removed->next)
		*stack = removed->next;
	else
		*stack = removed->prev;
	return (removed);
}

static t_list	*add_stack(t_list *stack, t_list **to)
{
	t_list	*new;
	t_list	*current;
	t_list	*last;

	new = stack;
	current = *to;
	last = current->prev;
	if (current == NULL)
	{
		new->next = new;
		new->prev = new;
		*to = new;
		return (new);
	}
	new->next = current;
	new->prev = last;
	current->prev = new;
	last->next = new;
	*to = new;
	return (new);
}

void push(t_list **from, t_list **to)
{
	t_list	*stack;

	stack = remove_stack(from);
	if (stack)
		add_stack(stack, to);
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
