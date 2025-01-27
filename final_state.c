/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:36:39 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/27 13:42:06 by abdel-ha         ###   ########.fr       */
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
	if (data->player.img != NULL)
		mlx_destroy_image(data->mlx, data->player.img);
	if (data->enemy.img != NULL)
		mlx_destroy_image(data->mlx, data->enemy.img);
	if (data->wall.img != NULL)
		mlx_destroy_image(data->mlx, data->wall.img);
	if (data->coin.img != NULL)
		mlx_destroy_image(data->mlx, data->coin.img);
	if (data->exit.img != NULL)
		mlx_destroy_image(data->mlx, data->exit.img);
	if (data->floor.img != NULL)
		mlx_destroy_image(data->mlx, data->floor.img);
	if (data->background.img != NULL)
		mlx_destroy_image(data->mlx, data->background.img);
	if (data->moves_container.img != NULL)
		mlx_destroy_image(data->mlx, data->moves_container.img);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	free_data(data);
	free(data->mlx);
}
