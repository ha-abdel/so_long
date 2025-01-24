#include "so_long.h"
#include "string.h"

void	initialize_sprites(t_data *data)
{
	init_vars1(data);
	init_vars2(data);
	init_vars(data);
}

void	initiallize_resources(t_data *data, t_validation_infos *info,
		char **test_map)
{
	int	x;
	int	y;

	y = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, info->width * FRAM_WIDTH, info->height
			* FRAM_WIDTH, "so_long!");
	data->width = info->width;
	data->height = info->height;
	initialize_sprites(data);
	init_images(data, info);
	init_images1(data, info);
	render_map(data);
}

void	init_images(t_data *data, t_validation_infos *info)
{
	data->player.img = mlx_xpm_file_to_image(data->mlx, "textures/Run.xpm",
			&data->player.width, &data->player.height);
	data->player.addr = mlx_get_data_addr(data->player.img, &data->player.bpp,
			&data->player.line_len, &data->player.endian);
	data->enemy.img = mlx_xpm_file_to_image(data->mlx, "textures/enemy.xpm",
			&data->enemy.width, &data->enemy.height);
	data->enemy.addr = mlx_get_data_addr(data->enemy.img, &data->enemy.bpp,
			&data->enemy.line_len, &data->enemy.endian);
	data->wall.img = mlx_xpm_file_to_image(data->mlx, "textures/boxx.xpm",
			&data->wall.width, &data->wall.height);
	data->wall.addr = mlx_get_data_addr(data->wall.img, &data->wall.bpp,
			&data->wall.line_len, &data->wall.endian);
	data->floor.img = mlx_xpm_file_to_image(data->mlx, "textures/floor1.xpm",
			&data->floor.width, &data->floor.height);
	data->floor.addr = mlx_get_data_addr(data->floor.img, &data->floor.bpp,
			&data->floor.line_len, &data->floor.endian);
}

void	init_images1(t_data *data, t_validation_infos *info)
{
	data->coin.img = mlx_xpm_file_to_image(data->mlx, "textures/money4.xpm",
			&data->coin.width, &data->coin.height);
	data->coin.addr = mlx_get_data_addr(data->coin.img, &data->coin.bpp,
			&data->coin.line_len, &data->coin.endian);
	data->exit.img = mlx_xpm_file_to_image(data->mlx, "textures/door1.xpm",
			&data->exit.width, &data->exit.height);
	data->exit.addr = mlx_get_data_addr(data->exit.img, &data->exit.bpp,
			&data->exit.line_len, &data->exit.endian);
	data->moves_container.img = mlx_xpm_file_to_image(data->mlx,
			"textures/MOVES.xpm", &data->moves_container.width,
			&data->moves_container.height);
	data->moves_container.addr = mlx_get_data_addr(data->moves_container.img,
			&data->moves_container.bpp, &data->moves_container.line_len,
			&data->moves_container.endian);
	data->background.img = mlx_new_image(data->mlx, data->info->width
			* FRAM_WIDTH, data->info->height * FRAM_WIDTH);
	data->background.addr = mlx_get_data_addr(data->background.img,
			&data->background.bpp, &data->background.line_len,
			&data->background.endian);
}