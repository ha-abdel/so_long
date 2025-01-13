#include "so_long.h"


void draw_player(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    t_sprite frame = {0};

    data->player.img = mlx_xpm_file_to_image(data->mlx, "player.xpm", &data->player.width, &data->player.height);
    if (!data->player.img)
    {
        printf("Error: Failed to load player image.\n");
        return;
    }
    data->player.addr = mlx_get_data_addr(data->player.img, &data->player.bpp, &data->player.line_len, &data->player.endian);
    frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->player.img);
        return;
    }
    frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);
    fill_fram(&frame, &data->player, &data->floor);
    mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, frame.img);
}

void draw_wall(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    t_sprite frame = {0};

    data->player.img = mlx_xpm_file_to_image(data->mlx, "boxx.xpm", &data->player.width, &data->player.height);
    if (!data->player.img)
    {
        printf("Error: Failed to load player image.\n");
        return;
    }
    data->player.addr = mlx_get_data_addr(data->player.img, &data->player.bpp, &data->player.line_len, &data->player.endian);
    frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->player.img);
        return;
    }
    frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);
    fill_fram(&frame, &data->player, &data->floor);
    mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, frame.img);
}

void draw_floor(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    t_sprite frame = {0};

    data->player.img = mlx_xpm_file_to_image(data->mlx, "floor.xpm", &data->player.width, &data->player.height);
    if (!data->player.img)
    {
        printf("Error: Failed to load player image.\n");
        return;
    }
    data->player.addr = mlx_get_data_addr(data->player.img, &data->player.bpp, &data->player.line_len, &data->player.endian);
    frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->player.img);
        return;
    }
    frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);
    fill_fram(&frame, &data->player, &data->floor);
    mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, frame.img);
}

void draw_coin(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    t_sprite frame = {0};

    data->player.img = mlx_xpm_file_to_image(data->mlx, "money4.xpm", &data->player.width, &data->player.height);
    if (!data->player.img)
    {
        printf("Error: Failed to load player image.\n");
        return;
    }
    data->player.addr = mlx_get_data_addr(data->player.img, &data->player.bpp, &data->player.line_len, &data->player.endian);
    frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->player.img);
        return;
    }
    frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);
    fill_fram(&frame, &data->player, &data->floor);
    mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, frame.img);
}

void draw_exit(t_data *data, t_validation_infos *info, int s_x, int s_y)
{
    t_sprite frame = {0};

    data->player.img = mlx_xpm_file_to_image(data->mlx, "exit.xpm", &data->player.width, &data->player.height);
    if (!data->player.img)
    {
        printf("Error: Failed to load player image.\n");
        return;
    }
    data->player.addr = mlx_get_data_addr(data->player.img, &data->player.bpp, &data->player.line_len, &data->player.endian);
    frame.img = mlx_new_image(data->mlx, 100, 100);
    if (!frame.img)
    {
        printf("Error: Failed to create frame image.\n");
        mlx_destroy_image(data->mlx, data->player.img);
        return;
    }
    frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);
    fill_fram(&frame, &data->player, &data->floor);
    mlx_put_image_to_window(data->mlx, data->win, frame.img, s_x, s_y);
    mlx_destroy_image(data->mlx, frame.img);
}