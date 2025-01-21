#include "so_long.h"

void render_bg(t_data *data, t_validation_infos *info, char **test_map)
{
    int x;
    int y;

    y = 0;
    while (test_map[y])
    {
        x = 0;
        while (test_map[y][x])
        {
            draw_floor(data, info, x * 100, y * 100);
            x++;
        }
        y++;
    }
}
void render_frames(t_data *data, t_validation_infos *info, char **test_map)
{
    int x;
    int y;

    y = 0;
    while (test_map[y])
    {
        x = 0;
        while (test_map[y][x])
        {
            if(x == info->px && y == info->py)
                draw_player(data, info, x * 100, y * 100);
            else if(x == info->ex && y == info->ey && x != 0 && y != 0)
                draw_enemy(data, info, x * 100, y * 100);
            else if(test_map[y][x] == '1')
                draw_wall(data, info, x * 100, y * 100);
            else if(test_map[y][x] == 'E')
                draw_exit(data, info, x * 100, y * 100);
            else if(test_map[y][x] == 'C')
                draw_coin(data, info, x * 100, y * 100);
            else if (test_map[y][x] == '0')
                draw_floor(data, info, x * 100, y * 100);
            x++;
        }
        y++;
    }
}

int    render_map(t_data *data)
{

    // render_bg(data, data->info, data->test_map);
    render_frames(data, data->info, data->test_map);
    draw_bg(data, data->info, 0, 0);
    return 0;
}