#include "so_long.h"

void	store_cordinates_for_player(t_data *data, int x, int y)
{
	data->info->count_Player++;
	data->info->px = x;
	data->info->py = y;
	data->player.x = x;
	data->player.y = y;
}
void	store_cordinates_for_enemy(t_data *data, int x, int y)
{
	data->info->count_enemy++;
	data->info->ex = x;
	data->info->ey = y;
	data->enemy.x = x;
	data->enemy.y = y;
}