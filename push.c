#include "push_swap.h"
#include <stdio.h>

/*
	Take the first element at the top of a stack
	Do nothing the stack is empty
*/
// function which return the number of list in stack
// check done
int	count_list1(t_list *stack)
{
	int	cnt;
	t_list	*current;

	if (stack == NULL)
		return (0);
	cnt = 1;
	current = stack->next;
	while (current != stack)
	{
		cnt++;
		current = current->next;
	}
	return (cnt);
}
void	push(t_list **from_stack, t_list **to_stack)
{
	t_list	*first;

	first = *from_stack;
	*from_stack = first->next;
	if (*from_stack != NULL)
	{
		(*from_stack)->prev = first->prev;
		if (first->prev != NULL)
			first->prev->next = *from_stack;
	}
	if (*from_stack == first)
		*from_stack = NULL;
	if (*to_stack == NULL)
	{
		first->next = first;
		first->prev = first;
		//*to_stack = first;
	}
	else
	{
		first->next = *to_stack;
		first->prev = (*to_stack)->prev;
		(*to_stack)->prev->next = first;
		(*to_stack)->prev = first;
		//*to_stack = first;
	}
	*to_stack = first;
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
