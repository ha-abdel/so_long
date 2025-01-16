#include "so_long.h"
#include "get_next_line.h"
#include <strings.h>

int    check_next(t_data *data)
{
    data->action = 0;
    data->count_moves++;
    draw_player(data, data->info, data->info->px, data->info->py);
    if(data->test_map[data->info->py][data->info->px] == 'C')
    {
        data->collected_coins++;
        data->test_map[data->info->py][data->info->px] = '0';
        draw_floor(data, data->info, data->info->px, data->info->py);
    }
    else if(data->test_map[data->info->py][data->info->px] == 'E' && 
        data->collected_coins != data->info->count_coin)
        return (data->count_moves--, 1);
    else if(data->test_map[data->info->py][data->info->px] == 'E' && 
        data->collected_coins == data->info->count_coin)
    {
        draw_player(data, data->info, data->info->px, data->info->py);
        render_bg(data, data->info, data->test_map);
        printf("count : %d\n" , data->count_moves);
        // free()   free all resources here
        mlx_destroy_window(data->mlx, data->win);
        exit (0);
    }
    printf("count : %d\n" , data->count_moves);
    render_bg(data, data->info, data->test_map);
    return 0;
}

void    handle_action(t_data *data)
{
    if(data->action == 'l' && data->test_map[data->info->py][data->info->px - 1] != '1')
    {
        data->info->px -= 1;
        if(check_next(data))
            data->info->px += 1;
    }
    else if(data->action == 'r' && data->test_map[data->info->py][data->info->px + 1] != '1')
    {
        data->info->px += 1;
        if(check_next(data))
            data->info->px -= 1;
    }
    else if(data->action == 'u' && data->test_map[data->info->py - 1][data->info->px] != '1')
    {
        data->info->py -= 1;
        if(check_next(data))
            data->info->py += 1;
    }
    else if(data->action == 'd' && data->test_map[data->info->py + 1][data->info->px] != '1')
    {
        data->info->py += 1;
        if(check_next(data))
            data->info->py -= 1;
    }
}

int animate_player(t_data *data)
{
    // int *x;
    // int *y;
    // x = &data->info->px;
    // y = &data->info->py;
    
     handle_action(data);
     if(!data)
        return 1;
    // render_bg(data, data->info, data->test_map);
    // render_frames(data, data->info, data->test_map);
    // draw_bg(data, data->info, 0,0);
    render_map(data);
   return 0; 
}

int handle_key_press(int keycode, t_data *data) {
    if (keycode == ESCAPE) {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    if (keycode == LEFT && data->info->px > 1)
        data->action = 'l';
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
    t_data data;
    
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

    initiallize_resources(&data, data.info, data.test_map);

    mlx_key_hook(data.win,handle_key_press,&data);
    mlx_loop_hook(data.mlx, animate_player, &data);
    mlx_loop(data.mlx);
    return 0;
}
