#include "push_swap.h"
#include <stdio.h>

// check arguments whether they are all integer
// check done
void	ft_check_is_digit(char **argv)
{
	size_t	i;
	size_t	j;
	int			flag;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			flag = ft_isdigit(argv[i][j]);
			if (flag == 0)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

// does not work well!!!!
void	ft_check_size_argv(int argc, char **argv)
{
	long long	result;
	int				i;

	i = 1;
	while (i < argc)
	{
		result = ft_atoi(argv[i]);
		if (result == 0 && *argv[i] != '0' && ft_strncmp(argv[i], "0", 1))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		if (result > INT_MAX || result < INT_MIN)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

// check args whether there are duplicate arguments
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
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

// parent function which check arguments
// first and third functions are done
void	ft_check_arg(int argc, char **argv)
{
	ft_check_is_digit(argv);
	ft_check_size_argv(argc, argv);
	ft_check_dup(argc, argv);
}

t_list	*ft_init_stack()
{
	t_list	*stack;

	stack = (t_list *)malloc(sizeof(t_list));
	if (stack == NULL)
		exit(1);
	stack = NULL;
	return (stack);
}

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
	// doesn't need to free new_stack???
}

// check done
int	ft_is_sorted(t_list *a_stack)
{
	t_list	*current_stack;

	if (a_stack == NULL)
		return (1);
	current_stack = a_stack;
	while (current_stack->next != a_stack)
	{
		if (current_stack->value > current_stack->next->value)
			return (0);
		current_stack = current_stack->next;
	}
	return (1);
}

void	ft_free_stack(t_list *stack)
{
	t_list	*current;
	t_list	*tmp;

	if (stack == NULL)
		return ;
	current = stack;
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
	t_list	*a_stack;
	t_list	*b_stack;
	int		i;
	int		value;

	i = 1;
	if (argc < 2)
		return (-1);
	ft_check_arg(argc, argv);
	a_stack = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		i++;
		a_stack = ft_insert_node(a_stack, value);
	}
	if (ft_is_sorted(a_stack))
	{
		ft_free_stack(a_stack);
		return (0);
	}
	b_stack = ft_init_stack();
	ft_sort(&a_stack, &b_stack, argc);
	ft_free_stack(a_stack);
	ft_free_stack(b_stack);
	return (0);
}

/*
#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main()
{
    char *s = malloc(100);

    s = "hello world";
    puts(s);
    return (0);
}
*/
