#include "push_swap.h"
#include <stdio.h>

// check argments whether all argments are integer
// check done
void	ft_check_is_digit(char **argv)
{
	size_t	i;
	size_t	j;
	int	flag;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			flag = ft_isdigit(argv[i][j]);
			if (flag == 0)
				exit(1);
			j++;
		}
		i++;
	}
}

// check args whether all argv are not over int_max or under int_min
// does not work well!!!!
void	ft_check_size_argv(int argc, char **argv)
{
	int	result;
	int	i;

	i = 1;
	while (i < argc)
	{
		result = ft_atoi(argv[i]);
		//printf("result of %d argv:%lld\n",i,result);
		if (result == 0 && *argv[i] != '0' && ft_strncmp(argv[i], "0", 1))
			exit(1);
		if (result > INT_MAX || result < INT_MIN)
			exit(1);
		i++;
	}
}

// check args whether there is duplicate argments
// check done
void	ft_check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				exit(1);
			j++;
		}
		i++;
	}
}

// check argv arguments parent function
void	ft_check_arg(int argc, char **argv)
{
	ft_check_is_digit(argv);
	ft_check_size_argv(argc, argv);
	ft_check_dup(argc, argv);
}

t_list	*ft_init_stack()
{
	t_list	*new_stack;

	new_stack = (t_list *)malloc(sizeof(t_list));
	if (new_stack == NULL)
		exit(1);
	new_stack->value = '\0';
	new_stack->next = new_stack;
	new_stack->prev = new_stack;
	return (new_stack);
}

// insert values toward a_stack function
// may be check done
t_list	*ft_insert_node(t_list *a_stack, int value)
{
	t_list	*new_stack;
	t_list	*last_stack;

	new_stack = (t_list *)malloc(sizeof(t_list));
	if (new_stack == NULL)
		exit(1);
	new_stack->value = value;
	if (a_stack == NULL)
	{
		new_stack->next = new_stack;
		new_stack->prev = new_stack;
		return (new_stack);
	}
	else
	{
		last_stack = a_stack->prev;
		new_stack->next = a_stack;
		new_stack->prev = last_stack;
		a_stack->prev = new_stack;
		last_stack->next = new_stack;
		return (a_stack);
	}
}

// func that check whether arguments are already sorted or not
// check done
int	ft_issorted(t_list *a_stack)
{
	t_list	*current_stack;

	if (a_stack == NULL)
	{
		return (1);
	}
	current_stack = a_stack;
	while (current_stack->next != a_stack)
	{
		if (current_stack->value > current_stack->next->value)
			return (0);
		current_stack = current_stack->next;
	}
	return (1);
}

// function which free stack
// may be check done
void	ft_free_stack(t_list *stack)
{
	t_list	*current;
	t_list	*tmp;

	if (stack == NULL)
		return ;
	current = stack->next;
	while (current != stack)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(stack);
}

int main(int argc, char **argv)
{
	//t_list **a_stack;
	//t_list	**b_stack;
	t_list *a_stack;
	t_list	*b_stack;
	int	i;
	int	value;

	i = 1;
	if (argc < 2)
		return (-1);
	a_stack = NULL;
	b_stack = NULL;
	ft_check_arg(argc, argv);
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		i++;
		a_stack = ft_insert_node(a_stack, value);
	}
	//ft_issorted(*a_stack);
	//*b_stack = ft_init_stack();
	//ft_sort(a_stack, b_stack, argc);
	//t_list *current = *a_stack;
	if (ft_issorted(a_stack))
	{
		ft_free_stack(a_stack);
		ft_free_stack(b_stack);
		return (0);
	}
	b_stack = ft_init_stack();
	ft_sort(&a_stack, &b_stack, argc);
	t_list *current = a_stack;
	for (i = 0; i < argc - 1; i++) {
		printf("%di:%d\n", i, current->value);
		*current = *current->next;
		}
	return (0);
}

/*
int main(int argc, char **argv)
{
	t_list	**a_stack;
	t_list	**b_stack;

	if (argc < 2)
		return (-1);
	ft_check_arg(argv);
	ft_init_stack(argv, argc, a_stack);
	ft_insert_value()
	if (ft_issorted(a_stack))
	{
		ft_free_stack(a_stack);
		ft_free_stack(b_stack);
		return (0);
	}
	ft_sort(a_stack, b_stack, argc);
	ft_free_stack(a_stack);
	ft_free_stack(b_stack);
	return (0);
}

*/
