/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:15:35 by linliu            #+#    #+#             */
/*   Updated: 2025/07/01 10:47:12 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = ft_calloc(sizeof(char *), (map->height + 1)); // calloc
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			ft_free_arr(copy); //free all
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
static void	get_player_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				map->player_x = j; // x is width, j
				map->player_y = i; //y is heigth, i
				return;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(t_map *map, char **copy, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height || copy[y][x] == '1')
		return ;
	copy[y][x] = '1';
	flood_fill(map, copy, x + 1, y);
	flood_fill(map, copy, x - 1, y);
	flood_fill(map, copy, x, y + 1);
	flood_fill(map, copy, x, y - 1);
}

static int	check_collectibles_exits(char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_path_valid(t_map *map)
{
	int		x;
	int		y;
	char	**copy_grid;

	copy_grid = copy_map(map);
	if (!copy_grid)
		free_error_handle(map, "Map copy failed\n");
	get_player_pos(map);
	x = map->player_x;
	y = map->player_y;
	flood_fill(map, copy_grid, x, y);
	if (!check_collectibles_exits(copy_grid))
	{
		ft_free_arr(copy_grid);
		free_error_handle(map, "Invalid map path: unreachable collectibles or exit\n");
	}
	ft_free_arr(copy_grid);
}
