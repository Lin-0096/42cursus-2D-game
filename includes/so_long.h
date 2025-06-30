/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:49:45 by linliu            #+#    #+#             */
/*   Updated: 2025/06/30 22:55:01 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
//# include <stdlib.h> //exit
# include <stdio.h>  //perror
# include <fcntl.h>  //open

//# define WIDTH 800
//# define HEIGHT 600 //common window size
# define TILE_SIZE 64
# define MAX_TILE_NUMBER 1980
# define MAX_WINDOW_WIDTH 3840
# define MAX_WINDOW_HEIGHT 2160
# define WALL "./texture/wall.png"
# define FLOOR "./texture/floor.png"
# define PLAYER "./texture/player.png"
# define EXIT "./texture/exit.png"
# define COLLECTIBLE "./texture/collectible.png"

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		player;
	int		exit;
	int		collectible;
}	t_map;

typedef struct s_texture
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
}	t_texture;

typedef struct s_game
{
	t_texture	tex;
	mlx_t		*mlx;
	t_map		*map;
}	t_game;

//parse map
t_map	*read_map(const char *filename);
void	remove_newline(char *line);
void	validate_map(t_map *map);

//common utils
void	print_map(t_map *map, t_game *game); //debug,delete!!
void	init_map(t_map *map);
void	free_whole_map(t_map *map);
void	free_error_handle(t_map *map, char *str);

//check path
void	check_path_valid(t_map *map);

//game utils
void	terminate_with_error(t_game *game, char *str);

//render
void	render_map_background(t_game *game);
void	render_map_player_exit(t_game *game);
void	render_map_collectible(t_game *game);
void	init_game(t_game *game, const char *map_path);

#endif


/*px stands for pixel — it’s the smallest unit of a digital image or screen. 64*64 Clear enough for tile-based games
A tile is one block in your game map — for example, a wall, floor, collectible, or player position
One tile = One image of fixed pixel size, Usually: 1 tile = 64 × 64 pixels*/
