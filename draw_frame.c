/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:36:05 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 11:17:24 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_enemy_fram(t_data *data, t_sprite *sprite, int frame_nbr)
{
	unsigned int	color;
	int				sprite_x;
	int				x;
	int				y;

	data->frame.frame_index = frame_nbr;
	y = 0;
	while (y < 100)
	{
		x = 0;
		while (x < 100)
		{
			sprite_x = (frame_nbr - 1) * 100 + x;
			color = get_color(sprite, sprite_x, y);
			if (get_t(color) != 255)
				my_mlx_pixel_put(&data->frame, x, y, color);
			else
			{
				color = get_color(&data->floor, x, y);
				my_mlx_pixel_put(&data->frame, x, y, color);
			}
			x++;
		}
		y++;
	}
}

void	fill_fram(t_data *data, t_sprite *sprite, int frame_nbr)
{
	unsigned int	color;
	int				sprite_x;
	int				x;
	int				y;

	data->frame.frame_index = frame_nbr;
	y = 0;
	while (y < FRAM_WIDTH)
	{
		x = 0;
		while (x < FRAM_WIDTH)
		{
			sprite_x = (frame_nbr - 1) * 100 + x;
			color = get_color(sprite, sprite_x, y);
			if (get_t(color) != 255)
				my_mlx_pixel_put(&data->frame, x, y, color);
			else
			{
				color = get_color(&data->floor, x, y);
				my_mlx_pixel_put(&data->frame, x, y, color);
			}
			x++;
		}
		y++;
	}
}

void	fill_reverse_fram(t_data *data, t_sprite *sprite, int frame_nbr)
{
	unsigned int	color;
	int				sprite_x;
	int				x;
	int				y;

	data->frame.frame_index = frame_nbr;
	y = 0;
	while (y < FRAM_WIDTH)
	{
		x = 99;
		while (x >= 0)
		{
			sprite_x = ((frame_nbr - 1) * FRAM_WIDTH) + (99 - x);
			color = get_color(sprite, sprite_x, y);
			if (get_t(color) != 255)
				my_mlx_pixel_put(&data->frame, x, y, color);
			else
			{
				color = get_color(&data->floor, x, y);
				my_mlx_pixel_put(&data->frame, x, y, color);
			}
			x--;
		}
		y++;
	}
}

void	fill_bg(t_data *data, t_sprite *frame, int s_x, int s_y)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	while (y < 100)
	{
		x = 0;
		while (x < 100)
		{
			color = get_color(frame, x, y);
			my_mlx_pixel_put(&data->background, s_x + x, s_y + y, color);
			x++;
		}
		y++;
	}
}
