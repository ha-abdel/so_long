#include "get_next_line.h"
#include "so_long.h"


void	check_enemy_next(t_data *data, int *new_x, int *new_y)
{
	int dx = data->info->px - data->info->ex; 
    int dy = data->info->py - data->info->ey; 
	if (abs(dx) > abs(dy))
    {
        if (dx > 0 && data->test_map[*new_y][*new_x + 1] != '1')
		{
			data->enemy.dir = 1;
            (*new_x)++;
		}
        else if (dx < 0 && data->test_map[*new_y][(*new_x) - 1] != '1')
		{
			data->enemy.dir = -1;
            (*new_x)--;
		}
    }
    else 
    {
        if (dy > 0 && data->test_map[*new_y + 1][*new_x] != '1')
            (*new_y)++;
        else if (dy < 0 && data->test_map[(*new_y) - 1][*new_x] != '1')
            (*new_y)--;
    }
}


void move_enemy(t_data *data)
{
 
    int new_x = data->info->ex;
    int new_y = data->info->ey;
	char original_tile = data->test_map[new_y][new_x];
    check_enemy_next(data, &new_x, &new_y);
    if (new_x == data->info->px && new_y == data->info->py)
    {
		animate_enemy(data);
        printf("You lose!\n");
        exit(0); 
    }
    if (data->test_map[new_y][new_x] != '1' && data->test_map[new_y][new_x] != 'E')
    {
		if(original_tile == 'C')
        	data->test_map[data->info->ey][data->info->ex] = original_tile;
		else
			data->test_map[data->info->ey][data->info->ex] = '0';
        data->info->ex = new_x;
        data->info->ey = new_y;
		draw_enemy(data, data->info, data->info->ex, data->info->ey);
    }

    render_map(data);
}




int	animate_all(t_data *data)
{
	handle_action(data);
	if (!data)
		return (1);
	if (data->collected_coins == data->info->count_coin)
		animate_door(data);
    animate_player(data);
	
	move_enemy(data);
	// animate_enemy(data);
	render_map(data);
	
	return (0);
}

int	handle_key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == LEFT && data->info->px > 1)
	{
		data->player.action = 'l';
		data->player.dir = -1;
	}
	if (keycode == UP && data->info->py > 1)
		data->player.action = 'u';
	if (keycode == RIGHT && data->info->px + 1 < data->width - 1)
	{
		data->player.action = 'r';
		data->player.dir = 1;
	}
	if (keycode == DOWN && data->info->py + 1 < data->height - 1)
		data->player.action = 'd';
	return (0);
}




int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	data.info = ft_calloc(1, sizeof(t_validation_infos));
	data.map = get_map(av[1]);
	data.test_map = dup_map(data.map);
	if (!data.map || !data.test_map)
		return (free(data.map), free(data.test_map), 0);
	if (!check_map(data.test_map, &data))
		return (printf("map is invalid"), 0);
	data.test_map = dup_map(data.map);
	initiallize_resources(&data, data.info, data.test_map);
	mlx_loop_hook(data.mlx, animate_all, &data);
	mlx_key_hook(data.win, handle_key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

