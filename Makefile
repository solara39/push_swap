NAME	= push_swap.a
CC	= cc
CFLAG	= -Wall -Werror -Wextra
SRCS	=	push_swap.c \
		simple_sort.c \
		push.c \
		reverse.c \
		rotate.c \
		swap.c \
		utils.c
MAIN	=	push_swap.c
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean
