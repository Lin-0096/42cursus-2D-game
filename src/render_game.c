/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:29:46 by linliu            #+#    #+#             */
/*   Updated: 2025/07/02 19:18:58 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_map_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->width)
	{
		y = 0;
		while (y < game->map->height)
		{
			if (game->map->grid[y][x] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->tex.wall, x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game, "fail to put the wall image to window");
			}
			else
			{
				if (mlx_image_to_window(game->mlx, game->tex.floor, x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game, "fail to put the floor image to window");
			}
			y++;
		}
		x++;
	}
}

static void	render_map_collectible_exit(t_game *game)
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

void	render_game(t_game *game)
{
	render_map_background(game);
	render_map_collectible_exit(game);
	if (mlx_image_to_window(game->mlx, game->tex.player, game->map->player_x * TILE_SIZE, game->map->player_y * TILE_SIZE) < 0)
		terminate_with_error(game, "fail to put the player image to window");
}
