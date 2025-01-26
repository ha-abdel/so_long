/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:37:28 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 12:18:55 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESCAPE 65307
# define LEFT 97
# define UP 119
# define RIGHT 100
# define DOWN 115

# define FRAM_WIDTH 100

# include "get_next_line.h"
# include </home/abdel-ha/Downloads/minilibx-linux/mlx.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_sprite
{
	void				*img;
	int					width;
	int					height;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
	int					frame_count;
	int					frame_index;
	char				action;
	int					dir;
}						t_sprite;

typedef struct s_validation_infos
{
	int					count_player;
	int					count_coin;
	int					count_exit;
	int					count_enemy;
	int					ex;
	int					ey;
	int					px;
	int					py;
	int					width;
	int					height;
	int					collide;
}						t_validation_infos;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	char				**map;
	char				**test_map;
	int					width;
	int					height;
	int					collected_coins;
	t_sprite			player;
	t_sprite			enemy;
	t_sprite			wall;
	t_sprite			floor;
	t_sprite			coin;
	t_sprite			exit;
	t_sprite			background;
	t_sprite			frame;
	t_sprite			moves_container;
	t_validation_infos	*info;
	char				action;
	int					count_moves;
	int					frame_nbr;
}						t_data;

// check map functions prototypes
char					**get_map(char *file_path);
int						get_map_len(char *file_path);
int						ft_check_helper(char **map, int len, int map_len);
char					**get_map(char *file_path);
void					flood_fill(char **test_map, int x, int y);
int						check_map(char **test_map, t_data *data);
char					**dup_map(char **map);
// void print_map(char **s);

void					init_vars3(t_data *data);
void					fill_fram(t_data *data, t_sprite *sprite,
							int frame_nbr);
int						get_t(int trgb);
unsigned int			get_color(t_sprite *img, int x, int y);
void					my_mlx_pixel_put(t_sprite *img, int x, int y,
							int color);

void					store_cordinates_for_enemy(t_data *data, int x, int y);

void					store_cordinates_for_player(t_data *data, int x, int y);
// initialise functions
void					render_frames(t_data *data, t_validation_infos *info,
							char **test_map);

// void	*ft_calloc(size_t count, size_t size);

// void					render_bg(t_data *data, t_validation_infos *info,
// 							char **test_map);

int						render_map(t_data *data);
void					fill_fram(t_data *data, t_sprite *sprite,
							int frame_nbr);

void					fill_enemy_fram(t_data *data, t_sprite *sprite,
							int frame_nbr);

void					fill_reverse_fram(t_data *data, t_sprite *sprite,
							int frame_nbr);
void					fill_moves_fram(t_data *data, t_sprite *sprite,
							int frame_nbr);
void					draw_player(t_data *data, int s_x, int s_y);
void					draw_exit(t_data *data, int s_x, int s_y);
void					draw_coin(t_data *data, int s_x, int s_y);
void					draw_floor(t_data *data, int s_x, int s_y);
void					draw_wall(t_data *data, int s_x, int s_y);
void					draw_bg(t_data *data, int s_x, int s_y);

void					draw_moves(t_data *data, int s_x, int s_y);

void					draw_enemy(t_data *data, int s_x, int s_y);

void					init_images(t_data *data);

void					init_images1(t_data *data);

void					init_vars(t_data *data);

void					init_vars2(t_data *data);
int						initiallize_resources(t_data *data,
							t_validation_infos *info);
void					render_bg(t_data *data, char **test_map);
void					render_frames(t_data *data, t_validation_infos *info,
							char **test_map);
void					fill_bg(t_data *data, t_sprite *frame, int s_x,
							int s_y);
int						render_map(t_data *data);
int						animate_player(t_data *data);

int						animate_door(t_data *data);

int						animate_enemy(t_data *data);
int						check_next(t_data *data, int old_x, int old_y);

void					handle_action(t_data *data);

int						close_window(t_data *data);

// void fill_fram(t_sprite *fram,t_sprite *sprite);
unsigned int			get_color(t_sprite *img, int x, int y);
void					my_mlx_pixel_put(t_sprite *img, int x, int y,
							int color);

char					*ft_itoa(int n);

// libft_functions

size_t					ft_strlcpy(char *dst, char *src, size_t dstsize);
char					*ft_strtrim(char *s1, char *set);
char					*ft_strchr(char *s, int c);
int						ft_strlen(char *s);

void					*ft_memset(void *b, int c, size_t len);

void					*ft_calloc(size_t count, size_t size);

void					ft_putstr(char *s);

int						ft_strncmp(char *s1, char *s2, int n);

void					free_data(t_data *data);

void					cleanup_resources(t_data *data);

int						check_file_name(char *file_path);
#endif