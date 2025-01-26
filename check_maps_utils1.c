/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:36:00 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 11:41:32 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	store_cordinates_for_player(t_data *data, int x, int y)
{
	data->info->count_player++;
	data->info->px = x;
	data->info->py = y;
}

void	store_cordinates_for_enemy(t_data *data, int x, int y)
{
	data->info->count_enemy++;
	data->info->ex = x;
	data->info->ey = y;
}

int	check_file_name(char *file_path)
{
	int	i;

	i = ft_strlen(file_path) - 4;
	if (i > 0 && ft_strncmp(file_path + i, ".ber", 4) == 0)
		return (1);
	return (0);
}
