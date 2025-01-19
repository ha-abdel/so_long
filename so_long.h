#ifndef SO_LONG_H
#define SO_LONG_H

#define ESCAPE 65307
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364

#define FRAM_WIDTH 100

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include "get_next_line.h"

typedef struct s_sprite
{
    void    *img;
    int     width;
    int     height;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    int     x;
    int     y;
    int     frame_count;
    int     frame_index;
    char    action;
} t_sprite;

typedef struct s_validation_infos
{
    int count_Player;
    int count_coin;
    int count_exit;
    int count_enemy;
    int ex;
    int ey;
    int px;
    int py;
    int width;
    int height;
    int                 is_initialized;
} t_validation_infos;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    char    **map;
    char    **test_map;
    int     width;
    int     height;
    int     collected_coins;
    t_sprite   player;
    t_sprite    enemy;
    t_sprite    wall;
    t_sprite    floor;
    t_sprite    coin;
    t_sprite    exit;
    t_sprite    background;
    t_sprite    frame;
    t_validation_infos  *info;
    char                action;
    int                 count_moves;
    int                 frame_nbr;
    // int target_x;      // Target x position in pixels
    // int target_y;      // Target y position in pixels
    // int moving;        // 1 if the player is moving, 0 otherwise
    // int move_steps;    // Number of steps for smooth movement
    // int step_count;    // Counter to track incremental movement
    // int current_x;    // Current x position in pixels
    // int current_y;    // Current y position in pixels
    // int target_tile_x;
    // int target_tile_y;

} t_data;

// typedef struct s_window
// {
//     int width;
//     int height;
// } t_window;
// typedef struct s_sprite
// {
//     t_sprite     img;
//     int         x;
//     int         y;
// } t_sprite;


#define WIN_W 2000
#define WIN_H 2000


// check map functions prototypes
char **get_map(char *file_path);
int get_map_len(char *file_path);
int ft_check_helper(char **map, int len, int map_len);
char **get_map(char *file_path);
void flood_fill(char **test_map, int x, int y);
int check_map(char **test_map, t_data *data);
char **dup_map(char **map);
// void print_map(char **s);

void fill_fram(t_data *data, t_sprite *sprite, int frame_nbr);
int	get_t(int trgb);
unsigned int    get_color(t_sprite *img, int x, int y);
void my_mlx_pixel_put(t_sprite *img,int x, int y,int color);

void	store_cordinates_for_enemy(t_data *data, int x, int y);


void	store_cordinates_for_player(t_data *data, int x, int y);
// initialise functions
void render_frames(t_data *data, t_validation_infos *info, char **test_map);

void render_bg(t_data *data, t_validation_infos *info, char **test_map);

int    render_map(t_data *data);
void fill_fram(t_data *data, t_sprite *sprite, int frame_nbr);

void fill_enemy_fram(t_data *data, t_sprite *sprite, int frame_nbr);
void draw_player(t_data *data, t_validation_infos *info, int s_x, int s_y);
void draw_exit(t_data *data, t_validation_infos *info, int s_x, int s_y);
void draw_coin(t_data *data, t_validation_infos *info, int s_x, int s_y);
void draw_floor(t_data *data, t_validation_infos *info, int s_x, int s_y);
void draw_wall(t_data *data, t_validation_infos *info, int s_x, int s_y);
void draw_bg(t_data *data, t_validation_infos *info, int s_x, int s_y);

void draw_enemy(t_data *data, t_validation_infos *info, int s_x, int s_y);


void    init_images(t_data *data, t_validation_infos *info);
void    initiallize_resources(t_data *data,t_validation_infos *info,char **test_map);
void render_bg(t_data *data, t_validation_infos *info, char **test_map);
void render_frames(t_data *data, t_validation_infos *info, char **test_map);
void    fill_bg(t_data *data, t_sprite *frame, int s_x, int s_y);
int     render_map(t_data *data);
int     animate_player(t_data *data); 

int     animate_door(t_data *data); 

int     animate_enemy(t_data *data); 
int	check_next(t_data *data, int old_x, int old_y);

void	handle_action(t_data *data);

int close_window(t_data *data);


// void fill_fram(t_sprite *fram,t_sprite *sprite);
unsigned int    get_color(t_sprite *img, int x, int y);
void my_mlx_pixel_put(t_sprite *img,int x, int y,int color);



// libft_functions

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(char *s, int c);
int	ft_strlen(char *s);
#endif