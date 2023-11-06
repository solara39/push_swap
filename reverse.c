#include "push_swap.h"

/*
	Shift down all elements of a stack by 1
	The last element becomes the first one
*/

void	reverse(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = first->prev;
	*stack = last;
}

void	do_rra(t_list **a_stack)
{
	reverse(a_stack);
	ft_putendl_fd("rra", 1);
}

void	do_rrb(t_list **b_stack)
{
	reverse(b_stack);
	ft_putendl_fd("rrb", 1);
}

void	do_rrr(t_list **a_stack, t_list **b_stack)
{
	reverse(a_stack);
	reverse(b_stack);
	ft_putendl_fd("rrr", 1);
}
