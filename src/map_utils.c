/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:33:03 by linliu            #+#    #+#             */
/*   Updated: 2025/07/02 10:37:37 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map, t_game *game) //for debug,delete!!
{
	int	i;

	i = 0;
	while(map->grid[i])
	{
		ft_putstr_fd(map->grid[i], 1);
		write(1, "\n", 1);
		i++;
	}
	printf("Window size: width = %d, height = %d\n", game->map->width * TILE_SIZE, game->map->height * TILE_SIZE);
	printf("height:%i, width:%i\n", map->height, map->width);
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	map->player_x = 0;
	map->player_y = 0;
}

void	free_whole_map(t_map *map)
{
	if (!map)
		return ;
	if (map->grid)
	{
		ft_free_arr(map->grid);
		map->grid = NULL;
	}
	free(map);
}

void	free_error_handle(t_map *map, char *str)
{
	if (map)
		free_whole_map(map);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (str && *str)
		ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	remove_newline(char *line)
{
	int		i;

	if (!line) //check NULL
		return ;
	i = (int)ft_strlen(line);
	if (i > 0 && line[i - 1] == '\n') // if line is an empty line(seg fault)
	{
		line[i - 1] = '\0';
	}
}

int	is_empty_line(t_map *map)
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
