#include "push_swap.h"

/*
	Shift up all elements of a stack by 1
	The first element becomes the last one
*/

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = (*stack)->prev;
	*stack = first->next;
	(*stack)->prev = last;
	last->next = first;
	first->next = *stack;
	first->prev = last;
}

void	do_ra(t_list **a_stack)
{
	rotate(a_stack);
	ft_putendl_fd("ra", 1);
}

void	do_rb(t_list **b_stack)
{	
	rotate(b_stack);
	ft_putendl_fd("rb", 1);
}

void	do_rr(t_list **a_stack, t_list **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	ft_putendl_fd("rr", 1);
}
