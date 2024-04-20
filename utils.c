#include "push_swap.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

static int	ft_handle_sign(const char *str, int *index)
{
	int	sign;

	sign = 1;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			sign *= -1;
		(*index)++;
	}
	return (sign);
}

static int	ft_handle_overflow(const char *str, int index, int sign, size_t count)
{
	char *_;

	_ = (char *)str;
	if (count > ft_strlen("9223372036854775807"))
		return (-1);
	else if (count == ft_strlen("9223372036854775807"))
	{
		if (sign < 0)
		{
			if (ft_strncmp(_, "9223372036854775808", 19) > 0)
				return (0);
		}
		else if (ft_strncmp(_, "9223372036854775807", 19) > 0)
			return (-1);
	}
	return (1);
}

static size_t count_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;

	return (i);
}


int	ft_atoi(const char *str)
{
	int				index;
	long long		result;
	int				sign;
	int				overflow;
	size_t			count;

	index = 0;
	result = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	sign = ft_handle_sign(str, &index);
	while (str[index] == '0')
		index++;
	count = count_len(str);
	while (ft_isdigit(str[index]))
	{
		result = (result * 10) + (str[index] - '0');
		overflow = ft_handle_overflow(str, index, sign, count);
		if (overflow != 1)
			return (overflow);
		index++;
	}
	return (result * sign);
}



int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	int				j;
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while ((p[i] != '\0' || q[i] != '\0') && (n > 0))
	{
		if (p[i] == q[i])
			i++;
		else
		{
			j = p[i] - q[i];
			return (j);
		}
		n--;
	}
	return (j);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
