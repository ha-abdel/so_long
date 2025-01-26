/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:37:19 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 10:26:20 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_bg(t_data *data, char **test_map)
{
	int	x;
	int	y;

	y = 0;
	while (test_map[y])
	{
		x = 0;
		while (test_map[y][x])
		{
            if (x == 0 && y == 0)
				x++;
			draw_floor(data, x * 100, y * 100);
			x++;
		}
		y++;
	}
}
void	render_frames(t_data *data, t_validation_infos *info, char **test_map)
{
	int	x;
	int	y;

	y = 0;
	while (test_map[y])
	{
		x = 0;
		while (test_map[y][x])
		{
			if (x == 0 && y == 0)
				draw_moves(data, x * 100, y * 100);
			else if (x == info->px && y == info->py)
				draw_player(data, x * 100, y * 100);
			else if (x == info->ex && y == info->ey && x != 0 && y != 0)
				draw_enemy(data, x * 100, y * 100);
			else if (test_map[y][x] == '1')
				draw_wall(data, x * 100, y * 100);
			else if (test_map[y][x] == 'E')
				draw_exit(data, x * 100, y * 100);
			else if (test_map[y][x] == 'C')
				draw_coin(data, x * 100, y * 100);
            else if (test_map[y][x] == '0')
				draw_floor(data, x * 100, y * 100);
			x++;
		}
		y++;
	}
}

int	render_map(t_data *data)
{
	// render_bg(data, data->test_map);
	render_frames(data, data->info, data->test_map);
	draw_bg(data, 0, 0);
	return (0);
}


void    free_data(t_data *data)
{
    int i;

    i = 0;
	if (data->test_map)
	{
		while (data->test_map[i])
    		free(data->test_map[i++]);
		free(data->test_map);
	}
    i = 0;
	if (data->map)
	{
		while (data->map[i])
        	free(data->map[i++]);
		free(data->map);
	}
    free(data->info);
    // free(data);
}
