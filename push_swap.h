#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

typedef struct list{
	struct list	*next;
	struct list	*prev;
	int		value;
}t_list;

int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_sort(t_list *a_stack, t_list *b_stack. int argc);

#endif
