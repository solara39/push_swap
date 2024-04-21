#include "push_swap.h"
#include <stdio.h>

/*
	Take the first element at the top of a stack
	Do nothing the stack is empty
*/

static t_list	*remove_stack(t_list **stack)
{
	t_list *removed;

	removed = *stack;
	if (removed == NULL)
		return (NULL);
	if (removed->next == removed)
	{
		*stack = NULL;
		removed->next = NULL;
		removed->prev = NULL;
		return (removed);
	}
	else
	{
		removed->next->prev = removed->prev;
		removed->prev->next = removed->next;
		*stack = removed->next;
		removed->next = NULL;
		removed->prev = NULL;
		return (removed);
	}
}

// function which return the number of list in stack
// check done
static int	count_list2(t_list *a_stack)
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

static t_list	*add_stack(t_list *stack, t_list **to)
{
	t_list	*current;
	t_list	*last;
	t_list	*tmp1;

	current = *to;
	if (current == NULL)
	{
		stack->next = stack;
		stack->prev = stack;
		*to = stack;
		return (stack);
	}
	else
	{
		last = current->prev;
		printf("last value is %d\n", last->value);
		stack->next = current;
		stack->prev = last;
		current->prev = stack;
		last->next = stack;
		*to = stack;
		return (*to);
	}
}

void push(t_list **from, t_list **to)
{
	t_list	*stack;
	t_list	*tmp1;
	t_list	*tmp2;

	stack = remove_stack(from);
	if (stack)
		*to = add_stack(stack, to); // bottleneck
	tmp1 = *from;
	tmp2 = *to;
	if (tmp1 != NULL)
		printf("length from %d\n", count_list2(tmp1));
	if (tmp2 != NULL)
		printf("length to %d\n", count_list2(tmp2));
	else
		printf("to is NULL\n");
}

void	do_pa(t_list **a_stack, t_list **b_stack)
{
	t_list *tmp1;
	t_list *tmp2;

	push(b_stack, a_stack);
	tmp1 = *a_stack;
	tmp2 = *b_stack;
	printf("a_stack values %d %d %d %d\n", tmp1->value, tmp1->next->value, tmp1->next->next->value, tmp1->next->next->next->value);
	ft_putendl_fd("pa", 1);
}

void	do_pb(t_list **a_stack, t_list **b_stack)
{
	push(a_stack, b_stack);
	ft_putendl_fd("pb", 1);
}
