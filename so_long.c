/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:37:23 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 15:49:02 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	check_enemy_next(t_data *data, int *new_x, int *new_y)
{
	int	dx;
	int	dy;

	dx = data->info->px - data->info->ex;
	dy = data->info->py - data->info->ey;
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

void	move_enemy(t_data *data)
{
	int		new_x;
	int		new_y;
	char	original_tile;

	new_x = data->info->ex;
	new_y = data->info->ey;
	original_tile = data->test_map[new_y][new_x];
	check_enemy_next(data, &new_x, &new_y);
	if (new_x == data->info->px && new_y == data->info->py)
	{
		animate_enemy(data);
		cleanup_resources(data);
		ft_putstr("You lose!\n");
		exit(0);
	}
	if (data->test_map[new_y][new_x] != '1'
		&& data->test_map[new_y][new_x] != 'E')
	{
		if (original_tile == 'C')
			data->test_map[data->info->ey][data->info->ex] = original_tile;
		else
			data->test_map[data->info->ey][data->info->ex] = '0';
		data->info->ex = new_x;
		data->info->ey = new_y;
	}
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
	render_map(data);
	return (0);
}

int	handle_key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
	{
		cleanup_resources(data);
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
		return (ft_putstr("expected args : so_long maps/map.ber"), 1);
	data.info = ft_calloc(1, sizeof(t_validation_infos));
	if (data.info == NULL)
		return (1);
	init_vars3(&data);
	data.map = get_map(av[1]);
	if (!data.map)
		return (free_data(&data), 1);
	data.test_map = dup_map(data.map);
	if (!data.test_map)
		return (free_data(&data), 1);
	if (!check_map(data.test_map, &data))
		return (free_data(&data), ft_putstr("map is invalid"), 1);
	data.test_map = dup_map(data.map);
	if (initiallize_resources(&data, data.info))
		return (free_data(&data), ft_putstr("failed to init ressources"), 1);
	mlx_loop_hook(data.mlx, animate_all, &data);
	mlx_key_hook(data.win, handle_key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (cleanup_resources(&data), 0);
}
