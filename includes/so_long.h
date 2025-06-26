/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:49:45 by linliu            #+#    #+#             */
/*   Updated: 2025/06/26 19:49:41 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# define WIDTH 800
//# define HEIGHT 600 //common window size
# define TILE_SIZE 32
# define MAX_WINDOW_WIDTH 1920
# define MAX_WINDOW_HEIGHT 1080

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
//# include <stdlib.h> //exit
# include <stdio.h>  //perror
# include <fcntl.h>  //open

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		player;
	int		exit;
	int		collectible;
}	t_map;

//parse map
t_map	*read_map(const char *filename);
void	remove_newline(char *line);
void	validate_map(t_map *map);

//common utils
void	print_map(char **map); //debug
void	init_map(t_map *map);
void	free_whole_map(t_map *map);
void	free_error_handle(t_map *map, char *str);

//check path
void	check_path_valid(t_map *map);

#endif
