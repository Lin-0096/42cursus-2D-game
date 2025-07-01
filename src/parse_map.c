/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:45:11 by linliu            #+#    #+#             */
/*   Updated: 2025/07/01 14:41:01 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_filename(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
		return (0);
	return (1);
}

static int	count_map_lines(t_map *map, const char *filename)
{
	int		fd;
	char	*new_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		exit(EXIT_FAILURE);
	}
	while ((new_line = get_next_line(fd)))
	{
		map->height++;
		free(new_line);
	}
	close(fd);
	if (map->height == 0 || map->height < 3)
		return (0);
	return (1);
}

static int	fill_map(t_map *map, int fd)
{
	int		i;
	char	*get_line;

	i = 0;
	while (i < map->height)
	{
		get_line = get_next_line(fd);
		if (!get_line)
			return (0);
		map->grid[i] = ft_strdup(get_line);
		free(get_line);
		if (!map->grid[i])
			return (0);
		remove_newline(map->grid[i]);
		i++;
	}
	map->grid[i] = NULL;
	return (1);
}

static int alloc_and_fill_map(t_map *map, const char *filename)
{
	int		fd;

	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		perror(filename);
		exit(EXIT_FAILURE);
	}
	if(!fill_map(map, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

t_map *read_map(const char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		free_error_handle(map, "Malloc failed\n");
	init_map(map);
	if (!check_filename(filename))
		free_error_handle(map, "Map file must have .ber extension\n");
	if (!count_map_lines(map, filename))
		free_error_handle(map, "Invalid map or empty\n");
	if (!alloc_and_fill_map(map, filename))
		free_error_handle(map, "Load map failed\n");
	map->width = (int)ft_strlen(map->grid[0]);
	if (map->width == 0 || map->width < 3)
		free_error_handle(map, "Invalid map or empty\n");
	if (map->width * TILE_SIZE > MAX_WINDOW_WIDTH
		||map->height * TILE_SIZE > MAX_WINDOW_HEIGHT
		||map->height * map->width > MAX_TILE_NUMBER) //where should i put this block??
		free_error_handle(map, "Map too large\n");
	validate_map(map);
	check_path_valid(map); //get player pos already
	return (map);
}
