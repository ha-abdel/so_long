/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:36:39 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 12:04:21 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	cleanup_resources(data);
	exit(0);
	return (0);
}

int	check_collision(t_data *data)
{
	if (data->info->px == data->info->py && data->info->ex == data->info->ey)
	{
		cleanup_resources(data);
		ft_putstr("You lose!\n");
		exit(0);
	}
	return (0);
}

void	cleanup_resources(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player.img);
	mlx_destroy_image(data->mlx, data->enemy.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->coin.img);
	mlx_destroy_image(data->mlx, data->exit.img);
	mlx_destroy_image(data->mlx, data->floor.img);
	mlx_destroy_image(data->mlx, data->background.img);
	mlx_destroy_image(data->mlx, data->moves_container.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_data(data);
	free(data->mlx);
}
