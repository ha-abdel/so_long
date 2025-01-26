/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:36:00 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/24 15:36:01 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	store_cordinates_for_player(t_data *data, int x, int y)
{
	data->info->count_Player++;
	data->info->px = x;
	data->info->py = y;
	data->player.x = x;
	data->player.y = y;
}
void	store_cordinates_for_enemy(t_data *data, int x, int y)
{
	data->info->count_enemy++;
	data->info->ex = x;
	data->info->ey = y;
	data->enemy.x = x;
	data->enemy.y = y;
}