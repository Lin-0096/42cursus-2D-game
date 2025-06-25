/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:45:11 by linliu            #+#    #+#             */
/*   Updated: 2025/06/25 13:05:31 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char *remove_newline()
// {

// }
char **read_map(const char *filename)
{
	int		fd;
	int		i;
	char	*new_line;
	char	**map;
	int		line;

	//count lines
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = 0;
	while ((new_line = get_next_line(fd)))
	{
		line++;
		free(new_line);
	}
	close(fd);
	//read map
	map = malloc(sizeof(char *) * (line + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_free_arr(map);
		return (NULL);
	}
	i = 0;
	while (i < line)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			ft_free_arr(map);
			close(fd);
			return(NULL);
		}
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	print_map(char **map) //for debug
{
	int	i;

	i = 0;
	while(map[i])
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}
}
