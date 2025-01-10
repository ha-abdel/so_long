#include "so_long.h"

// void draw_rectangle(void *mlx, void *win, int x, int y, int width, int height, int color)
// {
//     for (int i = 0; i < height; i++)
//     {
//         for (int j = 0; j < width; j++)
//         {
//             mlx_pixel_put(mlx, win, x + j, y + i, color); // Fill rows and columns
//         }
//     }
// }
void draw_circle( t_image img, int x, int y, int radius, int color);
// int handle_key_press(int keycode, t_data *data) {
//     if (keycode == 65307) { // Escape
//         mlx_destroy_image(data->mlx, data->img.img);
//         mlx_destroy_window(data->mlx, data->win);
//         perror("you win");
//         exit(0);
//     }
//     mlx_clear_window(data->mlx, data->win);

//     if (keycode == 65361 && data->player.player_x > 0) // Left arrow
//         data->player.player_x -= 200;
//     if (keycode == 65362 && data->player.player_y > 0) // Up arrow
//         data->player.player_y -= 200;
//     if (keycode == 65363 && data->player.player_x + 200 < WIN_W) // Right arrow
//         data->player.player_x += 200;
//     if (keycode == 65364 && data->player.player_y + 200 < WIN_H) // Down arrow
//         data->player.player_y += 200;

//     draw_circle(data->img, 100, 100, 100, 0xFF0000); // Redraw the circle
//     mlx_put_image_to_window(data->mlx, data->win, data->img.img, data->player.player_x, data->player.player_y);
//     return 0;
// }

// unsigned int color_lerp(unsigned int start, unsigned int end, float step)
// {
//     float r1 = (start >> 16) & 0xFF;
//     float g1 = (start >> 8) & 0xFF;
//     float b1 = start & 0xFF;

//     float r2 = (end >> 16) & 0xFF;
//     float g2 = (end >> 8) & 0xFF;
//     float b2 = end & 0xFF;

//     float r = r1 * (1.0 - step) + r2 * step;
//     float g = g1 * (1.0 - step) + g2 * step;
//     float b = b1 * (1.0 - step) + b2 * step;

//     return ((unsigned int)r << 16) | ((unsigned int)g << 8) | (unsigned int)b;
// }
void my_mlx_pixel_put(t_image img,int x, int y,int color)
{

        char *dst = img.addr + (y * img.line_len) + x * (img.bpp / 8);
        *(unsigned int *)dst = color;
    
}
void draw_circle( t_image img, int x, int y, int radius, int color)
{
    // //int i = 0;
    // int r = radius;
    // while (r >= 0)
    // {
    //   float angle = 0;
    //   while(angle <= 360)
    //   {
    //     int x1 = x + r * cos(angle * M_PI/180);
    //     int y1 = y + r * sin(angle * M_PI/180);
        
    //     my_mlx_pixel_put(img, x1 , y1 , color_lerp(0xFFFFFF, color, (float)r/radius));
    //     angle+= 0.01;
    //   }
    //    r--;
    
    int y1= y - radius;
    while (y1 <= y + radius)
    {
        int x1= x - radius;
        while (x1 <= x + radius)
        {
            if ((pow(x1 - x, 2) + pow(y1 - y, 2)) <= pow(radius, 2)) {
                my_mlx_pixel_put(img, x1, y1, color);
            }
            x1++;
        }
        y1++;
    }
}



int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    
    if (!data.mlx) {
        perror("Failed to initialize MiniLibX\n");
        return 1;
    }
    data.win = mlx_new_window(data.mlx, WIN_W, WIN_H, "so_long!");
    if (!data.win) {
        perror("Failed to create a new window\n");
        return 1;
    }
    data.player.player_x = 0;
    data.player.player_y = 0;
    data.img.img = mlx_new_image(data.mlx, WIN_W, WIN_H);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.line_len, &data.img.endian);
    draw_circle(data.img, 1000, 1000, 50, 0xFF0000);
    mlx_put_image_to_window(data.mlx, data.win, data.img.img, data.player.player_x, data.player.player_y);
    // mlx_key_hook(data.win,handle_key_press,&data);
    mlx_loop(data.mlx);
    return 0;
}
// void draw_circle(t_image img, int x, int y, int radius, int color) {
//     int r = radius;
//     while (r >= 0) {
//         for (float angle = 0; angle < 360; angle += 1) {
//             int x1 = x + r * cos(angle * M_PI / 180);
//             int y1 = y + r * sin(angle * M_PI / 180);
//             my_mlx_pixel_put(img, x1, y1, color_lerp(0xFFFFFF, color, (float)r / radius));
//         }
//         r--;
//     }
// }

// // int handle_key_press(int keycode, t_data *data) {
// //     if (keycode == 65307) { // Escape
// //         mlx_destroy_window(data->mlx, data->win_ptr);
// //         exit(0);
// //     }
// //     if (keycode == 65361 && data->player_x > 0) // Left arrow
// //         data->player_x -= 50;
// //     if (keycode == 65362 && data->player_y > 0) // Up arrow
// //         data->player_y -= 50;
// //     if (keycode == 65363 && data->player_x + 50 < WIN_W) // Right arrow
// //         data->player_x += 50;
// //     if (keycode == 65364 && data->player_y + 50 < WIN_H) // Down arrow
// //         data->player_y += 50;

// //     mlx_clear_window(data->mlx, data->win_ptr);
// //     mlx_put_image_to_window(data->mlx, data->win_ptr, data->img.img, data->player_x, data->player_y);

// //     return 0;
// // }

// int main(void) {
//     t_data data;

//     data.mlx = mlx_init();
//     data.win_ptr = mlx_new_window(data.mlx, WIN_W, WIN_H, "so_long!");
//     data.player_x = 100;
//     data.player_y = 100;
//     data.img.img = mlx_new_image(data.mlx, WIN_W / 2, WIN_H / 2);
//     data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.line_len, &data.img.endian);

//     draw_circle(data.img, WIN_W / 4, WIN_H / 4, 100, 0xFF0000);
//     mlx_put_image_to_window(data.mlx, data.win_ptr, data.img.img, data.player_x, data.player_y);

//     mlx_key_hook(data.win_ptr, handle_key_press, &data);
//     mlx_loop(data.mlx);
//     return 0;
// }
