#include "get_next_line.h"
#include "so_long.h"


int check_map_length(char **map)
{
    int len;
    int i = 0;
    if(!map || !*map)
        return 0;
    len = ft_strlen(map[0]);
    while (map[i])
    {
        if(ft_strlen(map[i]) != len)
            return 0;
        i++;
    }
    return 1;
}

int check_map_walls(char **map)
{
    int len;
    int map_len;

    map_len = 0;
    if(!map || !*map)
        return 0;
    len = ft_strlen(*map);
    while (map[map_len])
        map_len++;
    if(!ft_check_helper(map, len, map_len))
        return 0;
    return 1;
}

void check_map_elements(char **map, t_validation_infos *info)
{
    int y; 
    int x;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if(!ft_strchr("10PEC\n", map[y][x]))
                return ;
            if(map[y][x] == 'P')
            {
                info->count_Player++;
                info->px = x;
                info->py = y;
            }
            else if(map[y][x] == 'E')
                info->count_exit++;
            else if(map[y][x] == 'C')
                info->count_coin++;
            x++;
        }
        y++;
    }
}


int check_map(char **test_map)
{
    t_validation_infos info;
    int x;
    int y;

    y = 0;
    info.count_coin = 0;
    info.count_exit = 0;
    info.count_Player = 0;
    if(!check_map_length(test_map))
        return 0;
    if(!check_map_walls(test_map))
        return 0;
    check_map_elements(test_map, &info);
    if(info.count_Player != 1 || info.count_exit != 1 || info.count_coin <1)
        return 0;
    flood_fill(test_map, info.px, info.py);
    while (test_map[y])
    {
        x = 0;
        while (test_map[y][x])
        {
            if(ft_strchr("CEP", test_map[y][x++]))
                return 0;
        }
        y++;
    }
    return 1;
}
