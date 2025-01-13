#include "so_long.h"


void draw_player(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    t_sprite frame = {0};

    frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->player.img);
        return;
    }
    frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);
    fill_fram(&frame, &data->player, &data->floor);
    // mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, frame.img);
}

void draw_wall(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    t_sprite frame = {0};

    
    frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->wall.img);
        return;
    }
    frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);
    fill_fram(&frame, &data->wall, &data->floor);
    // mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, frame.img);
}

void draw_floor(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    t_sprite frame = {0};

    
    frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->floor.img);
        return;
    }
    frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);
    fill_fram(&frame, &data->floor, &data->floor);
    // mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, frame.img);
}

void draw_coin(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    t_sprite frame = {0};

    
    frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->coin.img);
        return;
    }
    frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);
    fill_fram(&frame, &data->coin, &data->floor);
    // mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, frame.img);
}

void draw_exit(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    t_sprite frame = {0};

    frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->exit.img);
        return;
    }
    frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);
    fill_fram(&frame, &data->exit, &data->floor);
    // mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, frame.img);
}

void draw_bg(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
        // fill_fram(&frame, &data->player, &data->background);
    mlx_put_image_to_window(data->mlx, data->win, data->background.img, s_x, s_y);
    // mlx_destroy_image(data->mlx, frame.img);
}