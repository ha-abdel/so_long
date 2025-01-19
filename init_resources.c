#include "so_long.h"
#include "string.h"


void    init_vars1(t_data *data)
{
    data->coin.addr = NULL;
    data->coin.img = NULL;
    data->player.addr = NULL;
    data->player.img = NULL;
    data->wall.addr = NULL;
    data->wall.img = NULL;
    data->floor.addr = NULL;
    data->floor.img = NULL;
    data->exit.addr = NULL;
    data->exit.img = NULL;
    data->background.addr = NULL;
    data->background.img = NULL;
    data->frame.addr = NULL;
    data->frame.img = NULL;
    data->enemy.addr = NULL;
    data->enemy.img = NULL;
   
}

void    init_vars(t_data *data)
{
    data->coin.x = 0;
    data->coin.y = 0;
    data->player.x = 0;
    data->player.y = 0;
    data->wall.x = 0;
    data->wall.y = 0;
    data->floor.x = 0;
    data->floor.y = 0;
    data->exit.x = 0;
    data->exit.y = 0;
    data->exit.frame_count = 9;
    data->exit.frame_index = 1;
    data->player.frame_count = 11;
    data->player.frame_index = 0;
    data->enemy.frame_count = 12;
    data->enemy.x = 0;
    data->enemy.y = 0;
    data->enemy.action = '0';
    data->player.action = '0';
    data->collected_coins = 0;
}

void    init_vars2(t_data * data)
{
    data->background.width = data->width * 100;
    data->background.height = data->height * 100;
    data->background.x = 0;
    data->background.y = 0;
    data->frame.width =100;
    data->frame.height = 100;
    data->frame.x = 0;
    data->frame.y = 0;
    data->action = 0;
    data->count_moves = 0; 
    data->frame_nbr = 0;
    data->enemy.frame_count = 12;
    data->enemy.frame_index = 1;
}

void    initialize_sprites(t_data *data)
{
    init_vars1(data);
    init_vars2(data);
    init_vars(data);
}



// void render_frames1(t_data *data, t_validation_infos *info, char **test_map)
// {
//     int x;
//     int y;

//     y = 0;
//     while (test_map[y])
//     {
//         x = 0;
//         while (test_map[y][x])
//         {
//             if(x == info->px && y == info->py)
//                 draw_player(data, info, x * 100, y * 100);
//             else if (test_map[y][x] == '0')
//                 draw_floor(data, info, x * 100, y * 100);  
//             x++;
//         }
//         y++;
//     }
// }

void initiallize_resources(t_data *data, t_validation_infos *info, char **test_map)
{
    int x;
    int y;

    y = 0;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, info->width * 100, info->height * 100, "so_long!");
    // printf("%d", data->info->width);
    data->width = info->width;
    data->height = info->height;
    // if(data->info->is_initialized == 0)
    //     {
            initialize_sprites(data);
            init_images(data, info);
            render_map(data);
        // }
}




void    init_images(t_data *data, t_validation_infos *info)
{
    data->player.img = mlx_xpm_file_to_image(data->mlx, "textures/Run.xpm", &data->player.width, &data->player.height);
    data->player.addr = mlx_get_data_addr(data->player.img, &data->player.bpp, &data->player.line_len, &data->player.endian);

     data->enemy.img = mlx_xpm_file_to_image(data->mlx, "textures/enemy.xpm", &data->enemy.width, &data->enemy.height);
    data->enemy.addr = mlx_get_data_addr(data->enemy.img, &data->enemy.bpp, &data->enemy.line_len, &data->enemy.endian);

    data->wall.img = mlx_xpm_file_to_image(data->mlx, "textures/boxx.xpm", &data->wall.width, &data->wall.height);
    data->wall.addr = mlx_get_data_addr(data->wall.img, &data->wall.bpp, &data->wall.line_len, &data->wall.endian);

    data->floor.img = mlx_xpm_file_to_image(data->mlx, "textures/floor1.xpm", &data->floor.width, &data->floor.height);
    data->floor.addr = mlx_get_data_addr(data->floor.img, &data->floor.bpp, &data->floor.line_len, &data->floor.endian);

    data->coin.img = mlx_xpm_file_to_image(data->mlx, "textures/money4.xpm", &data->coin.width, &data->coin.height);
    data->coin.addr = mlx_get_data_addr(data->coin.img, &data->coin.bpp, &data->coin.line_len, &data->coin.endian);

    data->exit.img = mlx_xpm_file_to_image(data->mlx, "textures/door1.xpm", &data->exit.width, &data->exit.height);
    data->exit.addr = mlx_get_data_addr(data->exit.img, &data->exit.bpp, &data->exit.line_len, &data->exit.endian);

     data->background.img = mlx_new_image(data->mlx,data->info->width * 100,data->info->height * 100);
     data->background.addr = mlx_get_data_addr(data->background.img, &data->background.bpp, &data->background.line_len, &data->background.endian);
}

