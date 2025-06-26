/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:33:03 by linliu            #+#    #+#             */
/*   Updated: 2025/06/26 11:20:08 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map) //for debug,delete!!
{
	int	i;

	i = 0;
	while(map->grid[i])
	{
		ft_putstr_fd(map->grid[i], 1);
		write(1, "\n", 1);
		i++;
	}
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

char	*remove_newline(char *line)
{
	size_t	i;

	if (!line) //check NULL
		return (NULL);
	i = ft_strlen(line);
	if (i > 0 && line[i - 1] == '\n') // if line is an empty line(seg fault)
	{
		line[i - 1] = '\0';
	}
	return (line);
}
