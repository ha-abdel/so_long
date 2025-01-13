#include "so_long.h"
#include "get_next_line.h"
#include <strings.h>

void    initialize_sprites(t_data *data)
{
    data->coin.addr = NULL;
    data->coin.img = NULL;
    data->coin.width = 100;
    data->coin.height = 100;
    data->coin.x = 0;
    data->coin.y = 0;

    data->player.addr = NULL;
    data->player.img = NULL;
    data->player.width = 100;
    data->player.height = 100;
    data->player.x = 0;
    data->player.y = 0;

    data->wall.addr = NULL;
    data->wall.img = NULL;
    data->wall.width = 100;
    data->wall.height = 100;
    data->wall.x = 0;
    data->wall.y = 0;

    data->floor.addr = NULL;
    data->floor.img = NULL;
    data->floor.width = 100;
    data->floor.height = 100;
    data->floor.x = 0;
    data->floor.y = 0;

    data->exit.addr = NULL;
    data->exit.img = NULL;
    data->exit.width = 100;
    data->exit.height = 100;
    data->exit.x = 0;
    data->exit.y = 0;

    data->background.addr = NULL;
    data->background.img = NULL;
    data->background.width = data->width * 100;
    data->background.height = data->height * 100;
    data->background.x = 0;
    data->background.y = 0;
    // data->background = {NULL, NULL, 100, 100, 0, 0};
}

void render_frames(t_data *data, t_validation_infos *info, char **test_map)
{
    int x;
    int y;

    y = 0;
    while (test_map[y])
    {
        x = 0;
        while (test_map[y][x])
        {
            if(!ft_strchr("10PEC\n", test_map[y][x]))
                return ;
            else if(test_map[y][x] == 'P')
                draw_player(data, info, x * 100, y * 100);
            else if(test_map[y][x] == '1')
                draw_wall(data, info, x * 100, y * 100);
            else if(test_map[y][x] == 'E')
                draw_exit(data, info, x * 100, y * 100);
            else if(test_map[y][x] == 'C')
                draw_coin(data, info, x * 100, y * 100);
            else if (test_map[y][x] == '0')
                draw_floor(data, info, x * 100, y * 100);   
            x++;
        }
        y++;
    }
}

void render_bg(t_data *data, t_validation_infos *info, char **test_map)
{
        int x;
    int y;

    y = 0;
    while (test_map[y])
    {
        x = 0;
        while (test_map[y][x])
        {
            draw_floor(data, info, x * 100, y * 100);
            x++;
        }
        y++;
    }
}
void initiallize_resources(t_data *data, t_validation_infos *info, char **test_map)
{
    int x;
    int y;

    y = 0;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, info->width * 100, info->height * 100, "so_long!");
    initialize_sprites(data);
    init_images(data, info);
    // while (test_map[y])
    // {
    //     x = 0;
    //     while (test_map[y][x])
    //     {
    //         if(!ft_strchr("10PEC\n", test_map[y][x]))
    //             return ;
    //         else if(test_map[y][x] == 'P')
    //             draw_player(data, info, x * 100, y * 100);
    //         else if(test_map[y][x] == '1')
    //             draw_wall(data, info, x * 100, y * 100);
    //         else if(test_map[y][x] == 'E')
    //             draw_exit(data, info, x * 100, y * 100);
    //         else if(test_map[y][x] == 'C')
    //             draw_coin(data, info, x * 100, y * 100);
    //         else if (test_map[y][x] == '0')
    //             draw_floor(data, info, x * 100, y * 100);   
    //         x++;
    //     }
    //     y++;
    // }
    render_bg(data, info, test_map);
    render_frames(data, info, test_map);
}

int handle_key_press(int keycode, t_data *data) {
    if (keycode == 65307) { // Escape
        //mlx_destroy_image(data->mlx, data->img.img);
        mlx_destroy_window(data->mlx, data->win);
        perror("you win");
        exit(0);
    }
    return 1;
    // mlx_clear_window(data->mlx, data->win_ptr);

    // if (keycode == 65361 && data->player_x > 0) // Left arrow
    //     data->player_x -= 200;
    // if (keycode == 65362 && data->player_y > 0) // Up arrow
    //     data->player_y -= 200;
    // if (keycode == 65363 && data->player_x + 200 < WIN_W) // Right arrow
    //     data->player_x += 200;
    // if (keycode == 65364 && data->player_y + 200 < WIN_H) // Down arrow
    //     data->player_y += 200;

    // draw_circle(data->img, 100, 100, 100, 0xFF0000); // Redraw the circle
    // mlx_put_image_to_window(data->mlx, data->win_ptr, data->img.img, data->player_x, data->player_y);
    // retur("map file is invalid"), 1);
}

void    init_images(t_data *data, t_validation_infos *info)
{
    data->player.img = mlx_xpm_file_to_image(data->mlx, "player.xpm", &data->player.width, &data->player.height);
    data->player.addr = mlx_get_data_addr(data->player.img, &data->player.bpp, &data->player.line_len, &data->player.endian);

    data->wall.img = mlx_xpm_file_to_image(data->mlx, "boxx.xpm", &data->wall.width, &data->wall.height);
    data->wall.addr = mlx_get_data_addr(data->wall.img, &data->wall.bpp, &data->wall.line_len, &data->wall.endian);

    data->floor.img = mlx_xpm_file_to_image(data->mlx, "floor.xpm", &data->floor.width, &data->floor.height);
    data->floor.addr = mlx_get_data_addr(data->floor.img, &data->floor.bpp, &data->floor.line_len, &data->floor.endian);

    data->coin.img = mlx_xpm_file_to_image(data->mlx, "money4.xpm", &data->coin.width, &data->coin.height);
    data->coin.addr = mlx_get_data_addr(data->coin.img, &data->coin.bpp, &data->coin.line_len, &data->coin.endian);

    data->exit.img = mlx_xpm_file_to_image(data->mlx, "exit.xpm", &data->exit.width, &data->exit.height);
    data->exit.addr = mlx_get_data_addr(data->exit.img, &data->exit.bpp, &data->exit.line_len, &data->exit.endian);

    data->exit.img = mlx_xpm_file_to_image(data->mlx, "floor.xpm", &data->exit.width, &data->exit.height);
    data->exit.addr = mlx_get_data_addr(data->exit.img, &data->exit.bpp, &data->exit.line_len, &data->exit.endian);

    data->background.img = mlx_xpm_file_to_image(data->mlx, "floor.xpm", &data->background.width, &data->background.height);
    data->background.addr = mlx_get_data_addr(data->background.img, &data->background.bpp, &data->background.line_len, &data->background.endian);

    // mlx_put_image_to_window(data->mlx, data->win, data->exit.img, 200, 200);
}

int main(int ac, char **av)
{
    int fd;
    char **test_map;
    t_validation_infos *info;
    t_data data;
    //t_sprite fram;
    
    if(ac != 2)
        return 1;
    info = ft_calloc(1 ,sizeof(t_validation_infos));
    data.map = get_map(av[1]);
    test_map = dup_map(data.map);
    if(!data.map || !test_map)
        return (free(data.map), free(test_map), 0);
    if(!check_map(test_map, info))
        return (printf("map is invalid"), 0);
    test_map = dup_map(data.map);
    // print_map(test_map);
    initiallize_resources(&data, info, test_map);
    // draw_player(&data, info, 200, 200);
    // draw_wall(&data, info, 400, 400);
    // draw_coin(&data, info, 500, 200);
    // //draw_floor(&data, info, 200, 500);
    // draw_exit(&data, info, 100, 100);
    // t_sprite *img;
    // img->width = 200;
    // img->height = 200;
    // img->img = mlx_xpm_file_to_image(data.mlx, "textures/Ninja Frog/Idle-_32x32_.xpm", &img->width, &img->height);
    // img->addr = mlx_get_data_addr(img->img,&img->bpp,&img->line_len,&img->endian);
    // fram.img= mlx_new_image(data.mlx,32,32);
    // fram.addr = mlx_get_data_addr(fram.img,&fram.bpp,&fram.line_len,&fram.endian);
    // fill_fram(&fram,img);
    
    // if(img.img == NULL)
    //     printf("read image failed");
    // // initiallize_resources(&data);
    // // data.player_x = 200;
    // // data.player_y = 200;
    // // data.img.img = mlx_new_image(data.mlx, 200, 200);
    // // data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.line_len, &data.img.endian);
    // mlx_put_image_to_window(data.mlx, data.win, fram.img, 200, 200);
      mlx_key_hook(data.win,handle_key_press,&data);
      mlx_loop(data.mlx);
    return 0;
}
