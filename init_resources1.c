/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resources1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:37:06 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 09:48:59 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars1(t_data *data)
{
	// data->coin.addr = NULL;
	// data->coin.img = NULL;
	// data->player.addr = NULL;
	// data->player.img = NULL;
	// data->wall.addr = NULL;
	// data->wall.img = NULL;
	// data->floor.addr = NULL;
	// data->floor.img = NULL;
	// data->exit.addr = NULL;
	// data->exit.img = NULL;
	// data->background.addr = NULL;
	// data->background.img = NULL;
	// data->frame.addr = NULL;
	// data->frame.img = NULL;
	// data->enemy.addr = NULL;
	// data->enemy.img = NULL;
	(void)data;
}

void	init_vars(t_data *data)
{
	data->coin.x = 0;
	data->coin.y = 0;
	data->player.x = 0;
	data->player.y = 0;
	data->wall.x = 0;
	data->wall.y = 0;
	data->floor.x = 0;
	data->floor.y = 0;
	data->exit.x = 0;
	data->exit.y = 0;
	data->exit.frame_count = 9;
	data->exit.frame_index = 1;
	data->player.frame_count = 11;
	data->player.frame_index = 0;
	data->enemy.frame_count = 12;
	data->enemy.x = 0;
	data->enemy.y = 0;
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
	data->background.x = 0;
	data->background.y = 0;
	data->frame.width = 100;
	data->frame.height = 100;
	data->frame.x = 0;
	data->frame.y = 0;
	data->action = 0;
	data->count_moves = 0;
	data->frame_nbr = 0;
	data->enemy.frame_count = 12;
	data->enemy.frame_index = 1;
	
}

void    init_vars3(t_data *data)
{
	data->info->collide = 0;
	data->info->count_coin = 0;
	data->info->count_enemy = 0;
	data->info->count_exit = 0;
	data->info->count_Player = 0;
	data->test_map = NULL;
	data->map = NULL;
}