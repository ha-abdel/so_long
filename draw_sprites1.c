/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:36:25 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/27 16:02:09 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_coin(t_data *data, int s_x, int s_y)
{
	data->frame.img = mlx_new_image(data->mlx, 100, 100);
	if (!data->frame.img)
	{
		printf("Error: Failed to create frame image.\n");
		mlx_destroy_image(data->mlx, data->frame.img);
		return ;
	}
	data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.line_len, &data->frame.endian);
	fill_fram(data, &data->coin, 1);
	fill_bg(data, &data->frame, s_x, s_y);
	mlx_destroy_image(data->mlx, data->frame.img);
}

void	draw_exit(t_data *data, int s_x, int s_y)
{
	data->frame.img = mlx_new_image(data->mlx, 100, 100);
	if (!data->frame.img)
	{
		printf("Error: Failed to create frame image.\n");
		mlx_destroy_image(data->mlx, data->frame.img);
		return ;
	}
	data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.line_len, &data->frame.endian);
	fill_fram(data, &data->exit, data->exit.frame_index);
	fill_bg(data, &data->frame, s_x, s_y);
	mlx_destroy_image(data->mlx, data->frame.img);
}

void	draw_bg(t_data *data, int s_x, int s_y)
{
	if (!data->win)
	{
		ft_putstr("Error\n Failed to create window.");
		cleanup_resources(data);
		exit(1);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->background.img, s_x,
		s_y);
}
