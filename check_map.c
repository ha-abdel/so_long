/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:41 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/27 16:01:56 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_length(char **map)
{
	int	len;
	int	i;

	i = 0;
	if (!map || !*map)
		return (0);
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_map_walls(char **map, t_validation_infos *info)
{
	int	len;
	int	map_len;

	map_len = 0;
	if (!map || !*map)
		return (0);
	len = ft_strlen(*map);
	while (map[map_len])
		map_len++;
	info->width = len;
	info->height = map_len;
	if (!ft_check_helper(map, len, map_len))
		return (0);
	return (1);
}

void	check_map_elements(char **map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr("10PECG\n", map[y][x]))
				return ;
			if (map[y][x] == 'P')
				store_cordinates_for_player(data, x, y);
			if (map[y][x] == 'G')
				store_cordinates_for_enemy(data, x, y);
			else if (map[y][x] == 'E')
				data->info->count_exit++;
			else if (map[y][x] == 'C')
				data->info->count_coin++;
			x++;
		}
		y++;
	}
}

int	check_map(char **test_map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!check_map_length(test_map) || !check_map_walls(test_map, data->info))
		return (0);
	check_map_elements(test_map, data);
	if (data->info->count_player != 1 || data->info->count_exit != 1
		|| data->info->count_coin < 1 || data->info->count_enemy > 1)
		return (0);
	flood_fill(test_map, data->info->px, data->info->py);
	while (test_map[y])
	{
		x = 0;
		while (test_map[y][x])
		{
			if (ft_strchr("CEP", test_map[y][x++]))
				return (0);
		}
		free(test_map[y]);
		test_map[y] = NULL;
		y++;
	}
	return (free(test_map), test_map = NULL, 1);
}
