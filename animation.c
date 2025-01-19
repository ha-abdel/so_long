#include "so_long.h"

int	animate_door(t_data *data)
{
	static int	frame = 0;
	static int	frame_timer = 0;
	if (data->exit.frame_index >= 9)
		return (1);
	if (frame_timer++ >= 2)
	{
		frame_timer = 0;
		data->exit.frame_index++;
	}
	return (0);
}

int	animate_enemy(t_data *data)
{
	static int	frame = 0;
	static int	frame_timer = 0;

	if (data->enemy.frame_index >= 12)
		data->enemy.frame_index = 0;
	if (frame_timer++ >= 8)
	{
		frame_timer = 0;
		data->enemy.frame_index++;
        // printf("%d\n", data)
        // draw_player(data, data->info, data->info->px, data->info->py);
	}
	return (0);
}

int	animate_player(t_data *data)
{
	static int	frame = 0;
	static int	frame_timer = 0;

	if (data->player.frame_index >= 11)
		data->player.frame_index = 0;
	if (frame_timer++ >= 1)
	{
		frame_timer = 0;
		data->player.frame_index++;
        // printf("%d\n", data)
        // draw_player(data, data->info, data->info->px, data->info->py);
	}
	return (0);
}

void	handle_action(t_data *data)
{
	if (data->player.action == 'l' && data->test_map[data->info->py][data->info->px
		- 1] != '1')
	{
		data->info->px -= 1;
		check_next(data, data->info->px + 1, data->info->py);
	}
	else if (data->player.action == 'r'
		&& data->test_map[data->info->py][data->info->px + 1] != '1')
	{
		data->info->px += 1;
		check_next(data, data->info->px - 1, data->info->py);
	}
	else if (data->player.action == 'u' && data->test_map[data->info->py
		- 1][data->info->px] != '1')
	{
		data->info->py -= 1;
		check_next(data, data->info->px, data->info->py + 1);
	}
	else if (data->player.action == 'd' && data->test_map[data->info->py
		+ 1][data->info->px] != '1')
	{
		data->info->py += 1;
		check_next(data, data->info->px, data->info->py - 1);
	}
}

int	check_next(t_data *data, int old_x, int old_y)
{
	data->player.action = 0;
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
    //  animate_player(data);
	// draw_player(data, data->info, data->info->px, data->info->py);
	printf("count : %d\n", data->count_moves);
	return (0);
}