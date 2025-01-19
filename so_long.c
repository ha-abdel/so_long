#include "get_next_line.h"
#include "so_long.h"
#include <strings.h>

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int check_collision(t_data *data)
{
    if (data->info->px == data->info->py && data->info->ex == data->info->ey)
    {
        printf("You lose!\n");
        exit(0);
    }
    return 0;
}

int	animate_door(t_data *data)
{
	static int	frame = 0;
	static int	frame_timer = 0;
	if (data->exit.frame_index >= 9)
		return (1);
	if (frame_timer++ >= 2)
	{
		frame_timer = 0;
		data->exit.frame_index++;
	}
	return (0);
}

int	animate_enemy(t_data *data)
{
	static int	frame = 0;
	static int	frame_timer = 0;

	if (data->enemy.frame_index >= 12)
		data->enemy.frame_index = 0;
	if (frame_timer++ >= 8)
	{
		frame_timer = 0;
		data->enemy.frame_index++;
        // printf("%d\n", data)
        // draw_player(data, data->info, data->info->px, data->info->py);
	}
	return (0);
}

int	animate_player(t_data *data)
{
	static int	frame = 0;
	static int	frame_timer = 0;

	if (data->player.frame_index >= 11)
		data->player.frame_index = 0;
	if (frame_timer++ >= 1)
	{
		frame_timer = 0;
		data->player.frame_index++;
        // printf("%d\n", data)
        // draw_player(data, data->info, data->info->px, data->info->py);
	}
	return (0);
}

void	move_enemy(t_data *data)
{
    int    enemy_x = data->info->ex * 100;
    int    enemy_y = data->info->ey * 100;
	// int    player_x = data->info->px * 100;
	// int    player_y = data->info->py * 100;


}
// int animate_player(t_data *data) {   
//     if (data->moving) {
//         int step_size = 10; // Smooth movement speed (pixels per frame)

//         // Move horizontally
//         if (data->info->px * 100 < data->target_x)
//             data->info->px += step_size;
//         else if (data->info->px * 100 > data->target_x)
//             data->info->px -= step_size;

//         // Move vertically
//         if (data->info->py * 100 < data->target_y)
//             data->info->py += step_size;
//         else if (data->info->py * 100 > data->target_y)
//             data->info->py -= step_size;

//         // Check if target is reached
//         if (data->info->px * 100 == data->target_x && data->info->py * 100 == data->target_y)
//             data->moving = 0; // Stop movement

//         // Update player frame
//         data->player.frame_index = (data->player.frame_index + 1) % data->player.frame_count;
//     }

//     // Redraw map
//     render_map(data);
//     return 0; 
// }


int	check_next(t_data *data, int old_x, int old_y)
{
	data->player.action = 0;
	data->count_moves++;
	draw_floor(data, data->info, old_x, old_y);
	if (data->test_map[data->info->py][data->info->px] == 'C')
	{
		data->collected_coins++;
		data->test_map[data->info->py][data->info->px] = '0';
	}
	else if (data->test_map[data->info->py][data->info->px] == 'E'
		&& data->collected_coins != data->info->count_coin)
		return (data->info->px = old_x, data->info->py = old_y,
			data->count_moves--, 1);
	else if (data->test_map[data->info->py][data->info->px] == 'E'
		&& data->collected_coins == data->info->count_coin)
	{
		printf("count : %d\n", data->count_moves);
		// free()   free all resources here
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	data->test_map[old_y][old_x] = '0';
    //  animate_player(data);
	// draw_player(data, data->info, data->info->px, data->info->py);
	printf("count : %d\n", data->count_moves);
	return (0);
}

void	handle_action(t_data *data)
{
	if (data->player.action == 'l' && data->test_map[data->info->py][data->info->px
		- 1] != '1')
	{
		data->info->px -= 1;
		check_next(data, data->info->px + 1, data->info->py);
	}
	else if (data->player.action == 'r'
		&& data->test_map[data->info->py][data->info->px + 1] != '1')
	{
		data->info->px += 1;
		check_next(data, data->info->px - 1, data->info->py);
	}
	else if (data->player.action == 'u' && data->test_map[data->info->py
		- 1][data->info->px] != '1')
	{
		data->info->py -= 1;
		check_next(data, data->info->px, data->info->py + 1);
	}
	else if (data->player.action == 'd' && data->test_map[data->info->py
		+ 1][data->info->px] != '1')
	{
		data->info->py += 1;
		check_next(data, data->info->px, data->info->py - 1);
	}
}



int	animate_all(t_data *data)
{
	handle_action(data);
	if (!data)
		return (1);
	if (data->collected_coins == data->info->count_coin)
	{
		// if (data->exit.frame_index < 10)
        // {
		animate_door(data);
            
        // }
	}
    animate_player(data);
	move_enemy(data);
	// animate_enemy(data);
	render_map(data);
	return (0);
}

int	handle_key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == LEFT && data->info->px > 1)
		data->player.action = 'l';
	if (keycode == UP && data->info->py > 1)
		data->player.action = 'u';
	if (keycode == RIGHT && data->info->px + 1 < data->width - 1)
		data->player.action = 'r';
	if (keycode == DOWN && data->info->py + 1 < data->height - 1)
		data->player.action = 'd';
	return (0);
}

// int handle_key_press(int keycode, t_data *data) {
//     if (keycode == ESCAPE) {
//         mlx_destroy_window(data->mlx, data->win);
//         exit(0);
//     }

//     if (data->moving) // Prevent new movement while still animating
//         return 0;

//     // Set target position based on key press
//     if (keycode == LEFT && data->info->px > 1) {
//         data->target_x = (data->info->px - 1) * 100; // Convert to pixels
//         data->target_y = data->info->py * 100;
//         data->moving = 1;
//         data->action = 'l';
//     }
//     if (keycode == RIGHT && data->info->px + 1 < data->width - 1) {
//         data->target_x = (data->info->px + 1) * 100;
//         data->target_y = data->info->py * 100;
//         data->moving = 1;
//         data->action = 'r';
//     }
//     if (keycode == UP && data->info->py > 1) {
//         data->target_x = data->info->px * 100;
//         data->target_y = (data->info->py - 1) * 100;
//         data->moving = 1;
//         data->action = 'u';
//     }
//     if (keycode == DOWN && data->info->py + 1 < data->height - 1) {
//         data->target_x = data->info->px * 100;
//         data->target_y = (data->info->py + 1) * 100;
//         data->moving = 1;
//         data->action = 'd';
//     }
//     return 0;
// }



int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac != 2)
		return (1);
	data.info = ft_calloc(1, sizeof(t_validation_infos));
	data.map = get_map(av[1]);
	data.test_map = dup_map(data.map);
	if (!data.map || !data.test_map)
		return (free(data.map), free(data.test_map), 0);
	if (!check_map(data.test_map, &data))
		return (printf("map is invalid"), 0);
	data.test_map = dup_map(data.map);
	initiallize_resources(&data, data.info, data.test_map);
	printf("%d", data.coin.width);
	mlx_loop_hook(data.mlx, animate_all, &data);
	mlx_key_hook(data.win, handle_key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	// mlx_loop_hook(data.mlx, animate_door, &data);
	mlx_loop(data.mlx);
	return (0);
}

