# include "push_swap.h"
# include <stdio.h>

// make ranking function
static size_t	min_position(t_list **stack)
{
	size_t	index;
	int     value;
	t_list	*current;

	current = *stack;
	value = current->value;
	current = current->next;
	index = 1;
	while (current != *stack)
	{
		if (value > current->value)
			index++;
		current = current->next;
	}
	return (index);
}

// coordinate compression function
static void	coordinate_compression(t_list **stack)
{
	t_list	*current;
	size_t	i;
	size_t			index;

	i = 1;
	current = *stack;
	while (i < count_list(*stack) + 1)
	{
		index = min_position(&current);
		current->index = index;
		current = current->next;
		i++;
	}
}

static void reverse_atob(t_list **a_stack, t_list **b_stack, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		do_pb(a_stack, b_stack);
		i++;
	}
}

static void btoa(t_list **a_stack, t_list **b_stack, size_t min, size_t max)
{
	size_t	a_push;
  size_t  i;
	t_list	*current;

	i = 0;
	a_push = count_list(*b_stack) / 2;
	while (i < a_push)
	{
		current = *b_stack;
		if (((min + max) / 2 < current->index) && current->index <= max)
		{
			do_pa(a_stack, b_stack);
			i++;
		}
		else
      do_rb(b_stack);
	}
	judge_b_stack(a_stack, b_stack, min, (min + max) / 2);
	reverse_atob(a_stack, b_stack, a_push);
	judge_b_stack(a_stack, b_stack, max - a_push + 1, max);
}

static void btoa_tail(t_list **a_stack, t_list **b_stack)
{
	size_t	i;

	i = 0;
	while (i < count_list(*b_stack))
	{
		do_pa(a_stack, b_stack);
		do_ra(a_stack);
	}
}

void	judge_b_stack(t_list **a_stack,t_list **b_stack, size_t min, size_t max)
{
	t_list	*current;
  size_t  b_cnt;

	current = *b_stack;
  b_cnt = count_list(*b_stack);
	if (b_cnt > 3)
		btoa(a_stack, b_stack, min, max);
	else if (b_cnt == 3)
	{
		sort_3(b_stack);
		btoa_tail(a_stack, b_stack);
	}
	else if (b_cnt == 2)
	{
		if (current->index > current->next->index)
		{
			do_rb(b_stack);
			btoa_tail(a_stack, b_stack);
		}
		else
			btoa_tail(a_stack, b_stack);
	}
}

void	quick_sort(t_list **a_stack, t_list **b_stack)
{
	size_t	a_cnt;
	size_t	b_push;
	size_t	i;
	t_list	*current;

	i = 0;
	a_cnt = count_list(*a_stack);
	b_push = a_cnt / 2;
	coordinate_compression(a_stack);
	while (count_list(*b_stack) < b_push)
	{
		current = *a_stack;
		if (current->index <= b_push)
			do_pb(a_stack, b_stack);
		else
			do_ra(a_stack);
	}
	judge_b_stack(a_stack, b_stack, 1, b_push);
	while (count_list(*b_stack) < a_cnt - b_push)
    do_pb(a_stack, b_stack);
	if (a_cnt % 2 == 0)
		i = a_cnt - b_push + 1;
	else
		i = a_cnt - b_push;
	judge_b_stack(a_stack, b_stack, i, a_cnt);
}
