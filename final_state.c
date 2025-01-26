/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:36:39 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 10:40:31 by abdel-ha         ###   ########.fr       */
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