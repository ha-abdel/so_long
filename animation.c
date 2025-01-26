/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:32 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 16:00:34 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animate_door(t_data *data)
{
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
	static int	frame_timer = 0;

	if (data->enemy.frame_index >= 12)
		data->enemy.frame_index = 0;
	if (frame_timer++ >= 7)
	{
		frame_timer = 0;
		data->enemy.frame_index++;
	}
	return (0);
}

int	animate_player(t_data *data)
{
	static int	frame_timer = 0;

	if (data->player.frame_index >= 11)
		data->player.frame_index = 0;
	if (frame_timer++ >= 0)
	{
		frame_timer = 0;
		data->player.frame_index++;
	}
	return (0);
}

void	handle_action(t_data *data)
{
	if (data->player.action == 'l'
		&& data->test_map[data->info->py][data->info->px - 1] != '1')
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
	else if (data->player.action == 'u'
		&& data->test_map[data->info->py - 1][data->info->px] != '1')
	{
		data->info->py -= 1;
		check_next(data, data->info->px, data->info->py + 1);
	}
	else if (data->player.action == 'd'
		&& data->test_map[data->info->py + 1][data->info->px] != '1')
	{
		data->info->py += 1;
		check_next(data, data->info->px, data->info->py - 1);
	}
}

int	check_next(t_data *data, int old_x, int old_y)
{
	data->player.action = 0;
	data->count_moves++;
	draw_floor(data, old_x, old_y);
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
		cleanup_resources(data);
		ft_putstr("you won");
		exit(0);
	}
	data->test_map[old_y][old_x] = '0';
	return (0);
}
