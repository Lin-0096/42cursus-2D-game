/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:29:46 by linliu            #+#    #+#             */
/*   Updated: 2025/06/30 22:42:10 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* mlx_load_png() Decode/load a PNG file into a buffer.
mlx_texture_t* mlx_load_png(const char* path);

mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture) It converts a texture into an image that can be drawn in your game window. ;

mlx_delete_texture(tex)； i don't need it anymore

mlx_image_to_window(mlx, img, x, y); Put the image into your game window
*/

static mlx_image_t	*load_texture(t_game *game, char *png_path)
{
	mlx_texture_t *tmp;
	mlx_image_t	*img;

	tmp = mlx_load_png(png_path);
	if (!tmp)
		terminate_with_error(game, "fail to load png\n");
	img = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	if (!img)
		return (NULL);
	return (img);
}

void	init_texture(t_game *game)
{
	game->tex.wall = load_texture(game, WALL);
	if (!game->tex.wall)
		terminate_with_error(game, "fail to convert wall texture\n");
	game->tex.floor = load_texture(game, FLOOR);
	if (!game->tex.floor)
		terminate_with_error(game, "fail to convert floor texture\n");
	game->tex.player = load_texture(game, PLAYER);
	if (!game->tex.player)
		terminate_with_error(game, "fail to convert player texture\n");
	game->tex.exit = load_texture(game, EXIT);
	if (!game->tex.exit)
		terminate_with_error(game, "fail to convert exit texture\n");
	game->tex.collectible = load_texture(game, COLLECTIBLE);
	if (!game->tex.collectible)
		terminate_with_error(game, "fail to convert collectible texture\n");
}
void	render_map_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->width)
	{
		y = 0;
		while (y < game->map->height)
		{
			if (game->map->grid[y][x] == '0')
			{
				if (mlx_image_to_window(game->mlx, game->tex.floor, x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game, "fail to put the floor image to window");
			}
			else if (game->map->grid[y][x] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->tex.wall, x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game, "fail to put the wall image to window");
			}
			y++;
		}
		x++;
	}
}

void	render_map_player_exit(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->width)
	{
		y = 0;
		while (y < game->map->height)
		{
			if (game->map->grid[y][x] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->tex.player, x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game, "fail to put the player image to window");
			}
			else if (game->map->grid[y][x] == 'E')
			{
				if (mlx_image_to_window(game->mlx, game->tex.exit, x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game, "fail to put the exit image to window");
			}
			y++;
		}
		x++;
	}
}

void	render_map_collectible(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->width)
	{
		y = 0;
		while (y < game->map->height)
		{
			if (game->map->grid[y][x] == 'C')
			{
				if (mlx_image_to_window(game->mlx, game->tex.collectible, x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game, "fail to put the collectible image to window\n");
			}
			y++;
		}
		x++;
	}
}

void	init_game(t_game *game, const char *map_path)
{
	game->map = read_map(map_path);
	game->mlx = mlx_init(game->map->height * TILE_SIZE, game->map->width * TILE_SIZE, "MEOW", false);
	if (!game->mlx)
		terminate_with_error(game, "mlx initialized failed\n");
	init_texture(game);
	render_map_background(game);
	render_map_collectible(game);
	render_map_player_exit(game);
}
