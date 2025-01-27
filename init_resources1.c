/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resources1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:37:06 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/27 15:00:07 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_data *data)
{
	data->exit.frame_count = 9;
	data->exit.frame_index = 1;
	data->player.frame_count = 11;
	data->player.frame_index = 0;
	data->enemy.frame_count = 12;
	data->enemy.action = '0';
	data->player.action = '0';
	data->collected_coins = 0;
	data->player.dir = 1;
	data->enemy.dir = 1;
}

void	init_vars2(t_data *data)
{
	data->background.width = data->width * 100;
	data->background.height = data->height * 100;
	data->frame.width = 100;
	data->frame.height = 100;
	data->action = 0;
	data->count_moves = 0;
	data->frame_nbr = 0;
	data->enemy.frame_count = 12;
	data->enemy.frame_index = 1;
}

void	init_vars3(t_data *data)
{
	data->info->collide = 0;
	data->info->count_coin = 0;
	data->info->count_enemy = 0;
	data->info->count_exit = 0;
	data->info->count_player = 0;
	data->test_map = NULL;
	data->map = NULL;
	data->coin.img = NULL;
	data->player.img = NULL;
	data->wall.img = NULL;
	data->floor.img = NULL;
	data->exit.img = NULL;
	data->background.img = NULL;
	data->frame.img = NULL;
	data->enemy.img = NULL;
	data->moves_container.img = NULL;
}
