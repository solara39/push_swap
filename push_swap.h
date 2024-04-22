#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

//the data structure "stack"
typedef struct list{
	struct list	*next;
	struct list	*prev;
	int					value;
	size_t			index;
} t_list;

int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putendl_fd(char *s, int fd);
int			ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void		ft_sort(t_list **a_stack, t_list **b_stack, int argc);
size_t	count_list(t_list *a_stack);
void		sort_3(t_list **a_stack);
void		quick_sort(t_list **a_stack, t_list **b_stack);
void		judge_b_stack(t_list **b_stack,t_list **a_stack, size_t min, size_t max);
void		do_sa(t_list **a_stack);
void		do_sb(t_list **b_stack);
void		do_ss(t_list **a_stack, t_list **b_stack);
void		do_ra(t_list **a_stack);
void		do_rb(t_list **b_stack);
void		do_rr(t_list **a_stack, t_list **b_stack);
void		do_rra(t_list **a_stack);
void		do_rrb(t_list **b_stack);
void		do_rrr(t_list **a_stack, t_list **b_stack);
void		do_pa(t_list **a_stack, t_list **b_stack);
void		do_pb(t_list **a_stack, t_list **b_stack);

#endif
