#include "so_long.h"

void my_mlx_pixel_put(t_sprite *img,int x, int y,int color)
{
     if (x < 0 || y < 0 || x >= img->width || y >= img->height)
        return;
    char *dst = img->addr + (y * img->line_len) + x * (img->bpp / 8);
    *(unsigned int *)dst = color;
}
unsigned int    get_color(t_sprite *img, int x, int y)
{
    int    offset;

    // if (x < 0 || y < 0 || x >= 100 || y >= 100)
    //     return (0);
    offset = (y * img->line_len) + (x * (img->bpp / 8));

    return (*(unsigned int *)(img->addr + offset));
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

void fill_fram(t_data *data, t_sprite *sprite, int frame_nbr)
{
    int x, y;
    unsigned int color;
    int sprite_x;

    data->frame.frame_index = frame_nbr;
    y = 0;
    while (y < 100)
    {
        x = 0;
        while (x < 100)
        {
            sprite_x = (frame_nbr - 1) * 100 + x;
            color = get_color(sprite, sprite_x, y);

            if (get_t(color) != 255)
                my_mlx_pixel_put(&data->frame, x, y, color);
            else
            {
                color = get_color(&data->floor, x, y);
                my_mlx_pixel_put(&data->frame, x, y, color);
            }
            x++;
        }
        y++;
    }
}