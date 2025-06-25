/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:33:03 by linliu            #+#    #+#             */
/*   Updated: 2025/06/25 21:33:42 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map) //for debug,delete!!
{
	int	i;

	i = 0;
	while(map[i])
	{
		ft_putstr_fd(map[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
}

void	free_whole_map(t_map *map)
{
	if (!map)
		return ;
	ft_free_arr(map->grid);
	free(map);
}

void	free_error_handle(t_map *map, char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	free_whole_map(map);
	exit(EXIT_FAILURE);
}
