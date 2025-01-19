#include "get_next_line.h"
#include "so_long.h"
#include <strings.h>





void	move_enemy(t_data *data)
{
    int    enemy_x = data->info->ex * 100;
    int    enemy_y = data->info->ey * 100;
	// int    player_x = data->info->px * 100;
	// int    player_y = data->info->py * 100;


}



int	animate_all(t_data *data)
{
	handle_action(data);
	if (!data)
		return (1);
	if (data->collected_coins == data->info->count_coin)
	{
		// if (data->exit.frame_index < 10)
        // {
		animate_door(data);
            
        // }
	}
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
		data->player.action = 'l';
	if (keycode == UP && data->info->py > 1)
		data->player.action = 'u';
	if (keycode == RIGHT && data->info->px + 1 < data->width - 1)
		data->player.action = 'r';
	if (keycode == DOWN && data->info->py + 1 < data->height - 1)
		data->player.action = 'd';
	return (0);
}




int	main(int ac, char **av)
{
	int		fd;
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
	printf("%d", data.coin.width);
	mlx_loop_hook(data.mlx, animate_all, &data);
	mlx_key_hook(data.win, handle_key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	// mlx_loop_hook(data.mlx, animate_door, &data);
	mlx_loop(data.mlx);
	return (0);
}

