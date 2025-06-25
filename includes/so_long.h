/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:49:45 by linliu            #+#    #+#             */
/*   Updated: 2025/06/25 12:52:11 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 800
# define HEIGHT 600 //common window size

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h> //exit
# include <stdio.h>  //perror
# include <fcntl.h>  //open

char	**read_map(const char *filename);
void	print_map(char **map);

#endif
