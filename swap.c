#include "push_swap.h"

/*
	Swap the 2 elemnts at the top of a stack.
	Do nothing if there is only one or no elemnts
*/

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	second->prev = first->prev;
	if (first->prev != NULL)
		first->prev->next = second;
	first->prev = second;
	*stack = second;
}

void	do_sa(t_list **a_stack)
{
	swap(a_stack);
	ft_putendl_fd("sa", 1);
}

void	do_sb(t_list **b_stack)
{
	swap(b_stack);
	ft_putendl_fd("sb", 1);
}

void	do_ss(t_list **a_stack, t_list **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_putendl_fd("ss", 1);
}
