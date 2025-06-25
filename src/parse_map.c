/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:45:11 by linliu            #+#    #+#             */
/*   Updated: 2025/06/25 22:00:04 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	count_map_lines(const char *filename)
{
	int		fd;
	char	*new_line;
	int		line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		exit(EXIT_FAILURE);
	}
	line = 0;
	while ((new_line = get_next_line(fd)))
	{
		line++;
		free(new_line);
	}
	close(fd);
	if (line == 0)
		return (0);
	return (line);
}

static int	fill_map(char **map, int fd, int line)
{
	int		i;
	char	*get_line;

	i = 0;
	while (i < line)
	{
		get_line = get_next_line(fd);
		if (!get_line)
		{
			ft_free_arr(map);
			return (0);
		}
		map[i++] = remove_newline(get_line);
	}
	map[i] = NULL;
	return (1);
}

static char	**alloc_fill_map(const char *filename, int line)
{
	char	**map;
	int		fd;

	map = malloc(sizeof(char *) * (line + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		perror(filename);
		exit(EXIT_FAILURE);
	}
	if(!fill_map(map, fd, line))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}

t_map *read_map(const char *filename)
{
	int		line;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		free_error_handle(map, "Malloc failed\n");
	init_map(map);
	line = count_map_lines(filename);
	if (line == 0)
		free_error_handle(map, "Invalid or empty map\n");
	map->grid = alloc_fill_map(filename, line);
	if (!map->grid)
		free_error_handle(map, "Failed to load map\n");
	map->height = line;
	map->width = ft_strlen(map->grid[0]);
	if (map->height < 3 || map->width < 3)
		free_error_handle(map, "Map is too small\n");
	validate_map(map);
	return (map);
}
