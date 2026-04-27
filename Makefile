NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS		= main.c utils.c node_ops.c stack_ops.c rotate_ops.c parsing.c \
			  io_ops.c init_stack.c special_ops.c split_ops.c index_calc.c \
			  simple.c hard_code.c disorder.c adaptive.c medium.c complex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
