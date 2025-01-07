# NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LFLAGS = -lmlx -lXext -lX11 -lm
SRCS = main.c get_next_line.c get_next_line_utils.c get_next_line.h so_long.h
# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

so_long: $(SRCS)
	$(CC) $(CFLAGS) $^ $(LFLAGS)

# $(NAME): $(OBJS)
# 	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf a.out

fclean: clean
	rm -rf a.out

re: fclean all