#include "push_swap.h"

/*
	Swap the 2 elemnts at the top of a stack.
	Do nothing if there is only one or no elemnts
*/

void	swap(t_list **stack)
{
}

void	do_sa(t_list **a_stack)
{
	swap(a_stack)
	ft_putendl_fd("sa", 1);
}

void	do_sb(t_list **b_stack)
{
	swap(b_stack)
	ft_putendl_fd("sb", 1);
}

void	do_ss(t_list **a_stack, t_list **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_putendl_fd("ss", 1);
}
