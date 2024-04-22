#include "push_swap.h"
#include <stdio.h>

size_t	count_list(t_list *a_stack)
{
	size_t	cnt;
	t_list	*current;

	cnt = 1;
	current = a_stack;
	if (current == NULL)
		return (0);
	while (current->next != a_stack)
	{
		cnt++;
		current = current->next;
	}
	return (cnt);
}

//function which return the position(index) of the smallest value
//check done
static size_t	find_index(t_list *stack, int smallest)
{
	t_list	*current;
	size_t	index;

	index = 0;
	current = stack;
	if (stack->value == smallest)
		return (index);
	current = stack->next;
	index++;
	while (current != stack)
	{
		if (current->value == smallest)
			return (index);
		index++;
		current = current->next;
	}
	return (0);
}

static int	get_min(t_list *stack)
{
	t_list	*current;
	int			smallest;

	smallest = stack->value;
	current = stack->next;
	while (current != stack)
	{
		if (smallest > current->value)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

static void	push_to_b(t_list **a_stack, t_list **b_stack, int smallest)
{
	size_t	index;
	size_t	mid_position;

	index = find_index(*a_stack, smallest);
	mid_position = count_list(*a_stack) / 2;
	while ((*a_stack)->value != smallest)
	{
		if (index < mid_position)
			do_ra(a_stack);
		else
			do_rra(a_stack);
	}
	do_pb(a_stack, b_stack);
}

// sort function when the number of arguments is 3
// check done
void	sort_3(t_list **a_stack)
{
	t_list *current;
	int			a;
	int			b;
	int			c;

	current = *a_stack;
	a = current->value;
	b = current->next->value;
	c = current->next->next->value;
	if (a > b && a < c)
		do_sa(a_stack);
	else if (a > b && a > c && b > c)
	{
		do_sa(a_stack);
		do_rra(a_stack);
	}
	else if (a > b && a > c && b < c)
		do_ra(a_stack);
	else if (a < b && a > c)
		do_rra(a_stack);
	else
	{
		do_sa(a_stack);
		do_ra(a_stack);
	}
}

// sort function when the number of arguments is 4, 5 or 6
// not checked yet
static void	sort_4_5_6(t_list **a_stack, t_list **b_stack)
{
	int	smallest;

	while (count_list(*a_stack) > 3)
	{
		smallest = get_min(*a_stack);
		push_to_b(a_stack, b_stack, smallest);
	}
	sort_3(a_stack);
	while (*b_stack != NULL)
		do_pa(a_stack, b_stack);
}

void	ft_sort(t_list **a_stack, t_list **b_stack, int argc)
{
	if (argc == 3)
		do_sa(a_stack);
	else if (argc == 4)
		sort_3(a_stack);
	else if (argc <= 7)
		sort_4_5_6(a_stack, b_stack);
	else
		quick_sort(a_stack, b_stack);
}
