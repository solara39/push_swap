#include "push_swap.h"

struct list
{
	long	value;
	struct list	*next;
	struct list	*prev;
}t_list;



void	ft_check_args(int argc, char ** argv)
{
}

int main(int argc, char **argv)
{
	struct t_list a_stack;
	struct t_list b_stack;

	a_stack = ft_initstack(argc, argv);//スタックの初期化
	if (check_stack(a_stack) == 1)
	{
		free_stack(&a_stack);
		return (0);
	}
	ft_check_args(argc, argv);
	else if (argc < 3)
		return (0);
	else if (argc == 3)
		ft_sort2();
	else if (argc == 4)1
		ft_sort3();
	else if (argc == 7)
		ft_sort6();
	else
		ft_sort_over7();
	free_stack(&a_stack)
	return (0);
}
