#include "so_long.h"
#include "get_next_line.h"

void initiallize_resources(t_data *data, t_validation_infos *info)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, info->width * 100, info->height * 100, "so_long!");
    t_sprite fram;

    
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

void my_mlx_pixel_put(t_sprite img,int x, int y,int color)
{

        char *dst = img.addr + (y * img.line_len) + x * (img.bpp / 8);
        *(unsigned int *)dst = color;
    
}
unsigned int    get_color(t_sprite img, int x, int y)
{
    int    offset;

    if (x < 0 || x >= 32 || y < 0 || y >= 32)
        return (0);
    offset = (y * img.line_len) + (x * (img.bpp / 8));
    return (*(unsigned int *)(img.addr + offset));
}
void fill_fram(t_sprite *fram,t_sprite sprite)
{
    int x,y;
    unsigned int color;
    y = 0;
    while (y < 32)
    {
        x = 0;
        while (x < 32)
        {
            
            color = get_color(sprite,x,y);
            // color = 0xFF0000;
            my_mlx_pixel_put(*fram,x,y,color);
            x++;
        }
        y++;
    }

}


int main(int ac, char **av)
{
    int fd;
    char **test_map;
    t_validation_infos *info;
    t_data data;
    
    if(ac != 2)
        return 1;
    info = ft_calloc(1 ,sizeof(t_validation_infos));
    data.map = get_map(av[1]);
    test_map = dup_map(data.map);
    if(!data.map || !test_map)
        return (free(data.map), free(test_map), 0);
    if(!check_map(test_map, info))
        return (printf("map is invalid"), 0);
    initiallize_resources(&data, info);

    // t_sprite img;
    // img.width = 200;
    // img.height = 200;
    // img.img = mlx_xpm_file_to_image(data.mlx, "textures/Ninja Frog/Idle-_32x32_.xpm", &img.width, &img.height);
    // img.addr = mlx_get_data_addr(img.img,&img.bpp,&img.line_len,&img.endian);
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
