/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:49:45 by linliu            #+#    #+#             */
/*   Updated: 2025/07/01 18:33:40 by linliu           ###   ########.fr       */
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
	int		player_x;
	int		player_y;
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
	int			moves_count;
}	t_game;

//parse map
t_map	*read_map(const char *filename);
void	validate_map(t_map *map);

//map utils
void	print_map(t_map *map, t_game *game); //debug,delete!!
void	init_map(t_map *map);
void	free_whole_map(t_map *map);
void	free_error_handle(t_map *map, char *str);
void	remove_newline(char *line);
int		is_empty_line(t_map *map);

//check path
void	check_path_valid(t_map *map);

//game utils
void	terminate_with_error(t_game *game, char *str);
void	close_game(t_game *game, char *str);
void	cleanup_image(t_game *game);
void		init_texture(t_game *game);

//render
void		render_game(t_game *game);
//mlx_image_t	*load_texture(t_game *game, char *png_path);

//start game
void	handle_input(mlx_key_data_t keydata, void *param);

#endif


/*px stands for pixel — it’s the smallest unit of a digital image or screen. 64*64 Clear enough for tile-based games
A tile is one block in your game map — for example, a wall, floor, collectible, or player position
One tile = One image of fixed pixel size, Usually: 1 tile = 64 × 64 pixels*/
