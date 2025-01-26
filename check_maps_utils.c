/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:52 by abdel-ha          #+#    #+#             */
/*   Updated: 2025/01/26 11:13:50 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	ft_check_helper(char **map, int len, int map_len)
{
	int	i;

	i = 0;
	while (map[map_len - 1][i])
	{
		if (map[map_len - 1][i] != '1' && map[map_len - 1][i] != '\n')
			return (0);
		i++;
	}
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != '\n')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || (map[i][len - 1] != '1' && map[i][len
				- 1] != '\n'))
			return (0);
		i++;
	}
	return (1);
}

char	**get_map(char *file_path)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;

	if (!check_file_name(file_path))
		return (NULL);
	map = malloc((get_map_len(file_path) + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file_path, O_RDWR);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	free(line);
	close(fd);
	return (map);
}

int	get_map_len(char *file_path)
{
	int		len;
	char	*line;
	int		fd;

	len = 0;
	fd = open(file_path, O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (len);
}

char	**dup_map(char **map)
{
	int		len;
	int		i;
	char	**newmap;
	char	*s;

	len = 0;
	i = 0;
	if (!map || !*map)
		return (NULL);
	while (map[len])
	{
		len++;
	}
	newmap = malloc(sizeof(char *) * (len + 1));
	if (!newmap)
		return (NULL);
	while (map[i])
	{
		s = ft_strtrim(map[i], "\n");
		newmap[i] = ft_strdup(s);
		free(s);
		i++;
	}
	newmap[i] = NULL;
	return (newmap);
}

void	flood_fill(char **test_map, int x, int y)
{
	if (x < 0 || y < 0 || test_map[y] == NULL || test_map[y][x] == '\0'
		|| test_map[y][x] == 'F' || test_map[y][x] == '1')
		return ;
	test_map[y][x] = 'F';
	flood_fill(test_map, x + 1, y);
	flood_fill(test_map, x - 1, y);
	flood_fill(test_map, x, y + 1);
	flood_fill(test_map, x, y - 1);
}
