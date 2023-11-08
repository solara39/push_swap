#include "push_swap.h"
#include <stdio.h>

// function which return the position(index) of the smallest value
// check done
int	find_index(t_list *stack, int smallest)
{
	t_list	*current;
	int	index;

	index = 0;
	current = stack;
	while (current->value != smallest)
	{
		index++;
		current = current->next;
	}
	return (index);
}


// funtion which return the smallest value in stack
// check done
int	get_min(t_list *stack)
{
	t_list	*current;
	int	smallest;
	int	flag;

	if (stack == NULL)
		exit(1);
	current = stack;
	smallest = stack->value;
	flag = 1;
	while (flag || current != stack)
	{
		flag = 0;
		current = current->next;
		if (smallest > current->value)
			smallest = current->value;
	}
	return (smallest);
}

// function which return the number of list in stack
// check done
int	count_list(t_list **stack)
{
	int	cnt;
	t_list	*current;

	if (*stack == NULL)
		return (0);
	cnt = 0;
	current = (*stack)->next;
	while (current != *stack)
	{
		cnt++;
		current = current->next;
	}
	return (cnt);
}

// function which will push the smallest argument toward b_stack
// not checked yet
void	push_to_b(t_list **a_stack, t_list **b_stack, int smallest)
{
	int	index;
	int	mid_position;
	int	stack_size;
	
	stack_size = count_list(a_stack);
	while ((*a_stack)->value != smallest)
	{	
		index = find_index(*a_stack, smallest);
		mid_position = count_list(a_stack) / 2;
		if (index <= mid_position)
			do_ra(a_stack);
		else
			do_rra(a_stack);
	}
	printf("len %d\n", count_list(a_stack));
	do_pb(a_stack, b_stack);
}

// sort function when the number of arguments is 3 
// check done
static void	sort_3(t_list **a_stack)
{
	t_list *current;
	int	a;
	int	b;
	int	c;

	current = *a_stack;
	a = current->value;
	b = current->next->value;
	c = current->next->next->value;
	if (a > b && a < c)
	{
		printf("1\n");
		do_sa(a_stack);
	}
	else if (a > b && a > c && b > c)
	{
		printf("2\n");
		do_sa(a_stack);
		do_rra(a_stack);
	}
	else if (a > b && a > c && b < c)
	{
		printf("3\n");
		do_ra(a_stack);
	}
	else if (a < b && a > c)
	{
		printf("5\n");
		do_rra(a_stack);
	}
	else
	{
		printf("4\n");
		do_sa(a_stack);
		do_ra(a_stack);
	}
}

// sort function when the number of arguments is 4, 5 or 6
// not checked yet
static void	sort_over4(t_list **a_stack, t_list **b_stack)
{
	int i = 0;
	while (count_list(a_stack) > 3)
		push_to_b(a_stack, b_stack, get_min(*a_stack));
	sort_3(a_stack);
	while (count_list(b_stack) > 0)
		do_pa(a_stack, b_stack);
}

static void	quick_sort(t_list **a_stack, t_list **b_stack)
{
}

// parent sort function
// manipulate which function will call depending on the number of arguments
// not checked yet
void	ft_sort(t_list **a_stack, t_list **b_stack, int argc)
{
	if (argc == 3)
		do_sa(a_stack);
	else if (argc == 4)
		sort_3(a_stack);
	else if (argc <= 7)
		sort_over4(a_stack, b_stack);
	else
		quick_sort(a_stack, b_stack);
}
