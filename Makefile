NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LFLAGS = -lmlx -lXext -lX11 -lm
SRCS = so_long.c check_map.c check_maps_utils.c get_next_line.c ft_putstr.c get_next_line_utils.c draw_sprites.c draw_frame.c init_resources.c render.c check_maps_utils1.c draw_func.c draw_sprites1.c animation.c final_state.c  libft_helpers.c init_resources1.c  itoa.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $@


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all