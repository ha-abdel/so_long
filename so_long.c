#include "so_long.h"
#include "get_next_line.h"



// int handle_key_press(int keycode, t_data *data) {
//     if (keycode == 65307) { // Escape
//         mlx_destroy_image(data->mlx, data->img.img);
//         mlx_destroy_window(data->mlx, data->win_ptr);
//         perror("you win");
//         exit(0);
//     }
//     mlx_clear_window(data->mlx, data->win_ptr);

//     if (keycode == 65361 && data->player_x > 0) // Left arrow
//         data->player_x -= 200;
//     if (keycode == 65362 && data->player_y > 0) // Up arrow
//         data->player_y -= 200;
//     if (keycode == 65363 && data->player_x + 200 < WIN_W) // Right arrow
//         data->player_x += 200;
//     if (keycode == 65364 && data->player_y + 200 < WIN_H) // Down arrow
//         data->player_y += 200;

//     draw_circle(data->img, 100, 100, 100, 0xFF0000); // Redraw the circle
//     mlx_put_image_to_window(data->mlx, data->win_ptr, data->img.img, data->player_x, data->player_y);
//     retur("map file is invalid"), 1);
// }


int main(int ac, char **av)
{
    int fd;
    char **test_map;
    // if(ac < 2)
    //     return 1;
    t_data data;
    data.map_file = ft_strdup(av[1]);
    // fd = open("maps/map1.ber", O_RDONLY);
    // if(fd < 0)
    //     return (perror("map file is invalid"), 1);
    data.map = get_map(data.map_file);
    test_map = get_map(data.map_file);
    int i=0;
    // while (test_map[i])
    // {
    //     printf("%s", test_map[i]);
    //     i++;
    // }
    if(!check_map(test_map))
    {
        perror("map is invalid");
        return 1;
    }
    // data.mlx = mlx_init();
    // data.win_ptr = mlx_new_window(data.mlx, WIN_W, WIN_H, "so_long!");
    // if (!data.mlx || !data.win_ptr)
    //     return (perror("Failed to initialize MiniLibX\n"), 1);
    // data.player_x = 200;
    // data.player_y = 200;
    // data.img.img = mlx_new_image(data.mlx, 200, 200);
    // data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.line_len, &data.img.endian);
    // mlx_put_image_to_window(data.mlx, data.win_ptr, data.img.img, data.player_x, data.player_y);
    // mlx_key_hook(data.win_ptr,handle_key_press,&data);
    // mlx_loop(data.mlx);
    return 0;
}
