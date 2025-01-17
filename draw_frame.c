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
    int x,y;
    unsigned int color;

    data->frame.frame_count = frame_nbr;
    y = frame_nbr - 1;
    while (y < frame_nbr * 100)
    {
        
        x = frame_nbr - 1;
        while (x < frame_nbr * 100)
        {
           color = get_color(sprite,x,y);
            //color = 0xFFFF00;
            if (get_t(color) != 255)
                my_mlx_pixel_put(&data->frame,x,y,color);
            else
            {
                color = get_color(&data->floor,x,y);
                my_mlx_pixel_put(&data->frame,x,y,color);
            }
            x++;
        }
        y++;
    }
}

// unsigned int    get_color1(void *img, int x, int y)
// {
//     int    offset;

//     // if (x < 0 || y < 0 || x >= 100 || y >= 100)
//     //     return (0);
//     offset = (y * 400 + (x * (4)));

//     return (*(unsigned int *)(&img + offset));
// }
void    fill_bg(t_data *data, t_sprite *frame, int s_x, int s_y)
{
    int x,y;
    unsigned int color;

    y = data->frame.frame_count - 1;
    
    while (y < data->frame.frame_count * 100)
    {
        
        x = data->frame.frame_count - 1;
        while (x < data->frame.frame_count * 100)
        {
            color = get_color(&data->frame, x, y);
            my_mlx_pixel_put(&data->background, s_x + x, s_y + y, color);
            x++;
        }
        y++;
    }
}