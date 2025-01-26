/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:36:19 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/24 15:36:20 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_data *data, int s_x, int s_y)
{
	data->frame.img = mlx_new_image(data->mlx, FRAM_WIDTH, FRAM_WIDTH);
	if (!data->frame.img)
	{
		perror("Error: Failed to create frame image.\n");
		mlx_destroy_image(data->mlx, data->frame.img);
		return ;
	}
	data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.line_len, &data->frame.endian);
	if (data->player.dir == 1)
		fill_fram(data, &data->player, data->player.frame_index);
	else
		fill_reverse_fram(data, &data->player, data->player.frame_index);
	fill_bg(data, &data->frame, s_x, s_y);
	mlx_destroy_image(data->mlx, data->frame.img);
}

void	draw_enemy(t_data *data, int s_x, int s_y)
{
	data->frame.img = mlx_new_image(data->mlx, FRAM_WIDTH, FRAM_WIDTH);
	if (!data->frame.img)
	{
		perror("Error: Failed to create frame image.\n");
		mlx_destroy_image(data->mlx, data->frame.img);
		return ;
	}
	data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.line_len, &data->frame.endian);
	if (data->enemy.dir == 1)
		fill_fram(data, &data->enemy, data->enemy.frame_index);
	else
		fill_reverse_fram(data, &data->enemy, data->enemy.frame_index);
	fill_bg(data, &data->frame, s_x, s_y);
	mlx_destroy_image(data->mlx, data->frame.img);
}

void	draw_wall(t_data *data, int s_x, int s_y)
{
	data->frame.img = mlx_new_image(data->mlx, FRAM_WIDTH, FRAM_WIDTH);
	if (!data->frame.img)
	{
		perror("Error: Failed to create frame image.\n");
		mlx_destroy_image(data->mlx, data->frame.img);
		return ;
	}
	data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.line_len, &data->frame.endian);
	fill_fram(data, &data->wall, 1);
	fill_bg(data, &data->frame, s_x, s_y);
	mlx_destroy_image(data->mlx, data->frame.img);
}

void	draw_floor(t_data *data, int s_x, int s_y)
{
	data->frame.img = mlx_new_image(data->mlx, FRAM_WIDTH, FRAM_WIDTH);
	if (!data->frame.img)
	{
		perror("Error: Failed to create frame image.\n");
		mlx_destroy_image(data->mlx, data->frame.img);
		return ;
	}
	data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.line_len, &data->frame.endian);
	fill_fram(data, &data->floor, 1);
	fill_bg(data, &data->frame, s_x, s_y);
	mlx_destroy_image(data->mlx, data->frame.img);
}

void	draw_moves(t_data *data, int s_x, int s_y)
{
	data->frame.img = mlx_new_image(data->mlx, FRAM_WIDTH, FRAM_WIDTH);
	if (!data->frame.img)
	{
		perror("Error: Failed to create frame image.\n");
		mlx_destroy_image(data->mlx, data->frame.img);
		return ;
	}
	data->frame.addr = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.line_len, &data->frame.endian);
	fill_moves_fram(data, &data->moves_container, 1);
	fill_bg(data, &data->frame, s_x, s_y);
	mlx_destroy_image(data->mlx, data->frame.img);
}
