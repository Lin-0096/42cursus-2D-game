/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:34:58 by linliu            #+#    #+#             */
/*   Updated: 2025/06/25 21:56:59 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_empty_line(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->grid)
		return (0);
	while (i < map->height)
	{
		if (!map->grid[i] || map->grid[i][0] == '\0' )
			return(0);
		i++;
	}
	return (1);
}

static int	other_chara(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			c = map->grid[i][j];
			if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_rectangle(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return (0);
	i = 1;
	while (map->grid[i])
	{
		if ((int)ft_strlen(map->grid[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

static int	is_surrounded_by_walls(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return (0);
	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while(i < map->height - 1)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	has_required_elements(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->grid)
		return (0);
	i = 0;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'P')
				map->player++;
			else if (map->grid[i][j] == 'E')
				map->exit++;
			else if (map->grid[i][j] == 'C')
				map->collectible++;
			j++;
		}
		i++;
	}
	return (map->player == 1 && map->exit == 1 && map->collectible >= 1);
}

void	validate_map(t_map *map)
{
	if (!is_empty_line(map))
		free_error_handle(map, "Map contains empty lines\n");
	if (!other_chara(map))
		free_error_handle(map, "Map contains other characters\n");
	if (!is_rectangle(map))
		free_error_handle(map, "Map is not rectangular\n");
	if (!is_surrounded_by_walls(map))
		free_error_handle(map, "Map is not surrounded by walls\n");
	if (!has_required_elements(map))
		free_error_handle(map, "Map must contain 1P, 1E, at least 1C\n");
}
