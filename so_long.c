#include "get_next_line.h"
#include "so_long.h"
#include <strings.h>

int	animate_door(t_data *data)
{
	static int	frame = 0;
	static int	frame_timer = 0;

	if (data->exit.frame_index >= 9)
		return (1);
	if (frame_timer++ >= 10)
	{
		frame_timer = 0;
		data->exit.frame_index++;
	}
	return (0);
}

int	animate_player(t_data *data)
{
	static int	frame = 0;
	static int	frame_timer = 0;

	if (data->player.frame_index >= 11)
		data->player.frame_index = 0;
	if (frame_timer++ >= 10)
	{
		frame_timer = 0;
		data->player.frame_index++;
        // printf("%d\n", data)
        // draw_player(data, data->info, data->info->px, data->info->py);
	}
	return (0);
}

int	check_next(t_data *data, int old_x, int old_y)
{
	data->action = 0;
	data->count_moves++;
	draw_floor(data, data->info, old_x, old_y);
	if (data->test_map[data->info->py][data->info->px] == 'C')
	{
		data->collected_coins++;
		data->test_map[data->info->py][data->info->px] = '0';
	}
	else if (data->test_map[data->info->py][data->info->px] == 'E'
		&& data->collected_coins != data->info->count_coin)
		return (data->info->px = old_x, data->info->py = old_y,
			data->count_moves--, 1);
	else if (data->test_map[data->info->py][data->info->px] == 'E'
		&& data->collected_coins == data->info->count_coin)
	{
		printf("count : %d\n", data->count_moves);
		// free()   free all resources here
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	data->test_map[old_y][old_x] = '0';
     animate_player(data);
	// draw_player(data, data->info, data->info->px, data->info->py);
	printf("count : %d\n", data->count_moves);
	return (0);
}

void	handle_action(t_data *data)
{
	if (data->action == 'l' && data->test_map[data->info->py][data->info->px
		- 1] != '1')
	{
		data->info->px -= 1;
		check_next(data, data->info->px + 1, data->info->py);
	}
	else if (data->action == 'r'
		&& data->test_map[data->info->py][data->info->px + 1] != '1')
	{
		data->info->px += 1;
		check_next(data, data->info->px - 1, data->info->py);
	}
	else if (data->action == 'u' && data->test_map[data->info->py
		- 1][data->info->px] != '1')
	{
		data->info->py -= 1;
		check_next(data, data->info->px, data->info->py + 1);
	}
	else if (data->action == 'd' && data->test_map[data->info->py
		+ 1][data->info->px] != '1')
	{
		data->info->py += 1;
		check_next(data, data->info->px, data->info->py - 1);
	}
}

int	animate_all(t_data *data)
{
	handle_action(data);
	if (!data)
		return (1);
	// printf("%d\n", data->frame_nbr);
	if (data->collected_coins == data->info->count_coin)
	{
		if (data->exit.frame_index < 10)
        {
			animate_door(data);
            
        }
	}
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
		data->action = 'l';
	if (keycode == UP && data->info->py > 1)
		data->action = 'u';
	if (keycode == RIGHT && data->info->px + 1 < data->width - 1)
		data->action = 'r';
	if (keycode == DOWN && data->info->py + 1 < data->height - 1)
		data->action = 'd';
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
	if (!check_map(data.test_map, data.info))
		return (printf("map is invalid"), 0);
	data.test_map = dup_map(data.map);
	initiallize_resources(&data, data.info, data.test_map);
	mlx_loop_hook(data.mlx, animate_all, &data);
	mlx_key_hook(data.win, handle_key_press, &data);
	// mlx_loop_hook(data.mlx, animate_door, &data);
	mlx_loop(data.mlx);
	return (0);
}
