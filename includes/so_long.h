/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:49:45 by linliu            #+#    #+#             */
/*   Updated: 2025/06/26 11:05:30 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 800
# define HEIGHT 600 //common window size

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
char	*remove_newline(char *line);
void	validate_map(t_map *map);

//common utils
void	print_map(t_map *map); //debug
void	init_map(t_map *map);
void	free_whole_map(t_map *map);
void	free_error_handle(t_map *map, char *str);

#endif
