#ifndef SO_LONG_H
#define SO_LONG_H


#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

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
} t_sprite;

// typedef struct s_player
// {
//     t_sprite    *player;
//     int         player_x;
//     int         player_y;

// } t_player;

// typedef struct s_coin
// {
//     t_sprite    *coin;
//     int         coin_x;
//     int         coin_y;
// } t_coin;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    int     count_coins;
    t_sprite   player;
    t_sprite    wall;
    t_sprite    floor;
    t_sprite    coin;
    t_sprite    exit;
    t_sprite    background;
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
typedef struct s_validation_infos
{
    int count_Player;
    int count_coin;
    int count_exit;
    int px;
    int py;
    int width;
    int height;
} t_validation_infos;


#define WIN_W 2000
#define WIN_H 2000

// check map functions prototypes
char **get_map(char *file_path);
int get_map_len(char *file_path);
int ft_check_helper(char **map, int len, int map_len);
char **get_map(char *file_path);
void flood_fill(char **test_map, int x, int y);
int check_map(char **test_map, t_validation_infos *info);
char **dup_map(char **map);
void print_map(char **s);




// initialise functions
void fill_fram(t_sprite *fram,t_sprite *sprite, t_sprite *bg);
void draw_player(t_data *data, t_validation_infos *info, int s_x, int s_y);
void draw_exit(t_data *data, t_validation_infos *info, int s_x, int s_y);
void draw_coin(t_data *data, t_validation_infos *info, int s_x, int s_y);
void draw_floor(t_data *data, t_validation_infos *info, int s_x, int s_y);
void draw_wall(t_data *data, t_validation_infos *info, int s_x, int s_y);
void    init_images(t_data *data, t_validation_infos *info);


// void fill_fram(t_sprite *fram,t_sprite *sprite);
unsigned int    get_color(t_sprite *img, int x, int y);
void my_mlx_pixel_put(t_sprite *img,int x, int y,int color);



// libft_functions

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(char *s, int c);
int	ft_strlen(char *s);
#endif