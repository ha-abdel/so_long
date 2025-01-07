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

typedef struct s_image
{
    void    *img;
    int     width;
    int     height;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
} t_image;

typedef struct s_player
{
    t_image    *player;
    int         player_x;
    int         player_y;

} t_player;

typedef struct s_coin
{
    t_image    *coin;
    int         coin_x;
    int         coin_y;
} t_coin;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    char    *map_file;
    char    **map;
    int     width;
    int     height;
    t_player player;
    // int     player_x;
    // int     player_y;
    t_image img;
} t_data;

typedef struct s_validation_infos
{
    int count_Player;
    int count_coin;
    int count_exit;
    int px;
    int py;
} t_validation_infos;


#define WIN_W 2000
#define WIN_H 2000

char **get_map(char *file_path);
int get_map_h(char *file_path);
int ft_check_helper(char **map, int len, int map_len);
char **get_map(char *file_path);
int get_map_h(char *file_path);
void flood_fill(char **test_map, int x, int y);
int check_map(char **test_map);

#endif