#include "so_long.h"

void my_mlx_pixel_put(t_sprite *img,int x, int y,int color)
{
     if (x < 0 || y < 0 || x > 100 || y > 100)
        return;
        char *dst = img->addr + (y * img->line_len) + x * (img->bpp / 8);
        *(unsigned int *)dst = color;
}
unsigned int    get_color(t_sprite *img, int x, int y)
{
    int    offset;

    if (x < 0 || y < 0 || x >= 100 || y >= 100)
        return (0);
    offset = (y * img->line_len) + (x * (img->bpp / 8));

    return (*(unsigned int *)(img->addr + offset));
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}
void fill_fram(t_sprite *fram,t_sprite *sprite, t_sprite *bg)
{
    int x,y;
    unsigned int color;
    y = 0;
    
    while (y < 100)
    {
        
        x = 0;
        while (x < 100)
        {
            color = get_color(sprite,x,y);
             //color = 0xFF0000;
            if (!get_t(color))
                my_mlx_pixel_put(fram,x,y,color);
            else
            {
                color = get_color(bg,x,y);
                my_mlx_pixel_put(fram,x,y,color);
            }
            x++;
        }
        y++;
    }
}