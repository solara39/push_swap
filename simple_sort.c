#include "push_swap.h"

int	get_min(t_list *a_stack)
{
	t_list	*current;
	int	smallest;

	smallest = a_stack->value;
	current = a_stack->next;
	while (current != a_stack)
	{
		if (smallest > current->value)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

void	push_to_b(t_list **a_stack, t_list **b_stack, int smallest)
{
	t_list	*current;

}

static void	sort_3(t_list *a_stack, t_list *b_stack)
{
	t_list *current;
	int	a;
	int	b;
	int	c;

	current = a_stack;
	a = current->value;
	b = current->next->value;
	c = current->next->next->value;
	if (a > b && a < c)
		sa(a_stack);
	else if (a > b && a > c && b > c)
	{
		sa(a_stack);
		rra(a_stack);
	}
	else if (a > b && a > c && b < c)
		ra(a_stack);
	else if (a < b && a > c)
		rra(a_stack);
	else
	{
		sa(a_stack);
		ra(a_stack);
	}
}

static void	sort_over4(t_list **a_stack, t_list **b_stack)
{
	int	smallest_index;

	smallest = get_min(a_stack);
	push_to_b(a_stack, b_stack, smallest);
	push_to_a(a_stack, b_stack);
}

static void	quick_sort(t_list *a_stack, t_list *b_stack)
{
}

void	ft_sort(t_list *a_stack, t_list *b_stack, int argc)
{
	if (argc == 3)
	{
		sa(a_stack);
	}
	else if (argc == 4)
	{
		sort_3(a_stack, b_stack);
	}
	else if (argc <= 7)
	{
		sort_over4(a_stack, b_stack);
	}
	else
	{
		quick_sort(a_stack, b_stack);
	}
}
