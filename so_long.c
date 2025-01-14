#include "so_long.h"
#include "get_next_line.h"
#include <strings.h>

void    check_next(t_data *data, int *x, int *y)
{
    if(data->test_map[*y][*x] == 'C')
    {
        data->collected_coins++;
        data->test_map[*y][*x] = '0';
    }
    if(data->test_map[*y][*x] == 'E')
    {
        if(data->collected_coins++ == data->info->count_coin)
        {
            //free()   free all resources here
            mlx_destroy_window(data->mlx, data->win);
            return ;
        }
    }
}

void    handle_action(t_data *data, int *x, int *y)
{
    if(data->action == 'l' && data->test_map[*y][*x - 1] != 1)
    {
        *x -= 1;
        check_next(data, x, y);
    }
    else if(data->action == 'r' && data->test_map[*y][*x + 1] != 1)
    {
        *x += 1;
        check_next(data, x, y);
    }
    else if(data->action == 'u' && data->test_map[*y][*y - 1] != 1)
    {
        *y -= 1;
        check_next(data, x, y);
    }
    else if(data->action == 'd' && data->test_map[*y][*y - 1] != 1)
    {
        *y += 1;
        check_next(data, x, y);
    }
}

int animate_player(t_data *data)
{
    int *x;
    int *y;

    printf("first  %d\n", *x);
    // printf("second %d\n", *y);
    x = &data->info->px;
    y = &data->info->py;
    // handle_action(data, x, y);
   return 0; 
}

int handle_key_press(int keycode, t_data *data) {
    if (keycode == ESCAPE) {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    if (keycode == LEFT && data->info->px > 1)
    {
        data->action = 'l';
    }
    if (keycode == UP && data->info->py > 1)
        data->action = 'u';
    if (keycode == RIGHT && data->info->px + 1 < data->width - 1)
        data->action = 'r';
    if (keycode == DOWN && data->info->py + 1 < data->height - 1)
        data->action = 'd';
    return 0;
}

int main(int ac, char **av)
{
    int fd;
    // char **test_map;
    // t_validation_infos *info;
    t_data data;

    //t_sprite fram;
    
    if(ac != 2)
        return 1;
    data.info = ft_calloc(1 ,sizeof(t_validation_infos));
    data.map = get_map(av[1]);
    data.test_map = dup_map(data.map);
    if(!data.map || !data.test_map)
        return (free(data.map), free(data.test_map), 0);
    if(!check_map(data.test_map, data.info))
        return (printf("map is invalid"), 0);
    data.test_map = dup_map(data.map);
    // print_map(data.test_map);
    initiallize_resources(&data, data.info, data.test_map);

    mlx_key_hook(data.win,handle_key_press,&data);
    mlx_loop_hook(data.mlx, animate_player, &data);
    mlx_loop(data.mlx);
    return 0;
}
