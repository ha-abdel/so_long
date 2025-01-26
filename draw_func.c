/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:36:13 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 09:43:13 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_it(t_data *data, unsigned int color, int x, int y)
{
	char	*count;

	count = ft_itoa(data->count_moves);
	if (x == 20 && y == 50)
		mlx_string_put(data->mlx, data->win, x + 1, y + 1, 0x0000FF00, count);
	if (x == 21 && y == 50)
		mlx_string_put(data->mlx, data->win, x + 1, y + 1, 0x0000FF00, count);
	if (x == 22 && y == 50)
		mlx_string_put(data->mlx, data->win, x + 1, y + 1, 0x0000FF00, count);
	else if (get_t(color) != 255)
		my_mlx_pixel_put(&data->frame, x, y, color);
	else
	{
		color = get_color(&data->floor, x, y);
		my_mlx_pixel_put(&data->frame, x, y, color);
	}
	free(count);
}

void	my_mlx_pixel_put(t_sprite *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_len) + x * (img->bpp / 8);
	*(unsigned int *)dst = color;
}

unsigned int get_color(t_sprite *img, int x, int y)
{
    if (x < 0 || y < 0 || x >= img->width || y >= img->height)
        return 0;

    int offset = (y * img->line_len) + (x * (img->bpp / 8));
    if (offset < 0 || offset >= img->width * img->height * (img->bpp / 8))
        return 0;

    return *(unsigned int *)(img->addr + offset);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

void	fill_moves_fram(t_data *data, t_sprite *sprite, int frame_nbr)
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
			sprite_x = (frame_nbr - 1) * FRAM_WIDTH + x;
			color = get_color(sprite, sprite_x, y);
			fill_it(data, color, x, y);
			x++;
		}
		y++;
	}
}
