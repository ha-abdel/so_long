#include "so_long.h"

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