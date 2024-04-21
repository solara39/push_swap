#include "push_swap.h"
#include <stdio.h>

// function which return the number of list in stack
// check done
int	count_list(t_list *a_stack)
{
	int	cnt;
	t_list	*current;

	cnt = 1;
	current = a_stack;
	while (current->next != a_stack)
	{
		cnt++;
		current = current->next;
	}
	return (cnt);
}

//function which return the position(index) of the smallest value
//check done
int	find_index(t_list *stack, int smallest)
{
	t_list	*current;
	t_list	*tmp;
	int	index;

	tmp = stack;
	for (int i = 1; i < count_list(stack) + 1; i++)
	{
		printf("value is %d\n", tmp->value);
		tmp = tmp->next;
	}
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


// function which return the smallest value in stack
// check done
int	get_min(t_list *stack)
{
	t_list	*current;
	int	smallest;

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

// function which will push the smallest argument toward b_stack
// not checked yet
void	push_to_b(t_list **a_stack, t_list **b_stack, int smallest)
{
	int	index;
	int	mid_position;

	index = find_index(*a_stack, smallest);
	printf("smallest arguments index i is %d\n", index);
	mid_position = count_list(*a_stack) / 2;
	printf("cnt is %d\n", count_list(*a_stack));
	printf("mid position is %d\n", mid_position);
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
	printf("a : %d\nb : %d\nc :%d\n", a, b, c);
	if (a > b && a < c)
	{
		printf("number 1\n");
		do_sa(a_stack);
	}
	else if (a > b && a > c && b > c)
	{
		printf("number 2\n");
		do_sa(a_stack);
		do_rra(a_stack);
	}
	else if (a > b && a > c && b < c)
	{
		printf("number 3\n");
		do_ra(a_stack);
	}
	else if (a < b && a > c)
	{
		printf("number 5\n");
		do_rra(a_stack);
	}
	else
	{
		printf("number 4\n");
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
		printf("sort_4_5_6 smallest value is %d\n", smallest);
		push_to_b(a_stack, b_stack, smallest); // may be mistaken
	}
	sort_3(a_stack);
	while (*b_stack != NULL)
	{
		do_pa(a_stack, b_stack);
		sleep(1000);
	}
}

int partition(t_list **stack, int left, int right)
{
	return (0);
}

// implement someday...
static void	coordinate_compression(t_list **stack)
{
	t_list	*current;
}

// recursive function to implement quick sort
// creating
static void sort_recursive(t_list **stack, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(stack, left, right);
		sort_recursive(stack, left, right);
	}
}

static void	quick_sort(t_list **a_stack, t_list **b_stack)
{
	size_t	cnt;

	cnt = count_list(*a_stack);
	sort_recursive(a_stack, 0, cnt);
}

// parent sort function
// decide which function should be called depending on the number of arguments
// not checked yet
void	ft_sort(t_list **a_stack, t_list **b_stack, int argc)
{
	if (argc == 3) // ok
	{
		printf("argc is 3\n");
		do_sa(a_stack);
	}
	else if (argc == 4) // ok
	{
		printf("argc is 4\n");
		sort_3(a_stack);
	}
	else if (argc <= 7)
	{
		printf("argc is %d\n", argc - 1);
		sort_4_5_6(a_stack, b_stack);
	}
	else
	{
		printf("arguments is over 7\n");
		quick_sort(a_stack, b_stack);
	}
}
