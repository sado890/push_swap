NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = main.c \
       parsing.c init_stack.c node_ops.c stack_ops.c rotate_ops.c \
	   special_ops.c \
       utils.c memory_ops.c string_ops.c split_ops.c index_calc.c disorder.c \
       adaptive.c simple.c medium.c medium_push.c complex.c complex_lis.c \
	   hard_code.c \
	   medium_utils.c \
	   io_ops.c

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
