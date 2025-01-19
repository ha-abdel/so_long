#include "so_long.h"


void draw_player(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    // t_sprite frame = {0};

    
    data->frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!data->frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->frame.img);
        return;
    }
    data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp, &data->frame.line_len, &data->frame.endian);
    fill_fram(data, &data->player, data->player.frame_index);
    //mlx_put_image_to_window(data->mlx, data->win, frame.img, 0, 0);
    fill_bg(data, &data->frame, s_x, s_y);
    //mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, data->frame.img);
}

void draw_enemy(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    // t_sprite frame = {0};

    
    data->frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!data->frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->frame.img);
        return;
    }
    data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp, &data->frame.line_len, &data->frame.endian);
    fill_enemy_fram(data, &data->enemy, data->enemy.frame_index);
    //mlx_put_image_to_window(data->mlx, data->win, frame.img, 0, 0);
    fill_bg(data, &data->frame, s_x, s_y);
    //mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, data->frame.img);
}

void draw_wall(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    // t_sprite frame = {0};

    data->frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!data->frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->frame.img);
        return;
    }
    data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp, &data->frame.line_len, &data->frame.endian);
    fill_fram(data, &data->wall, 1);
    fill_bg(data, &data->frame, s_x, s_y);
    // mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, data->frame.img);
}

void draw_floor(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    // t_sprite frame = {0};

    
    data->frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!data->frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->frame.img);
        return;
    }
    data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp, &data->frame.line_len, &data->frame.endian);
    fill_fram(data, &data->floor, 1);
    fill_bg(data, &data->frame, s_x, s_y);
    // mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, data->frame.img);
}

