/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:05:57 by linliu            #+#    #+#             */
/*   Updated: 2025/07/01 10:03:48 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cleanup_image(t_game *game)
{
	if (game->tex.wall)
		mlx_delete_image(game->mlx, game->tex.wall);
	if (game->tex.floor)
		mlx_delete_image(game->mlx, game->tex.floor);
	if (game->tex.player)
		mlx_delete_image(game->mlx, game->tex.player);
	if (game->tex.exit)
		mlx_delete_image(game->mlx, game->tex.exit);
	if (game->tex.collectible)
		mlx_delete_image(game->mlx, game->tex.collectible);
}

void	terminate_with_error(t_game *game, char *str)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	cleanup_image(game);
	free_error_handle(game->map, str);
}

mlx_image_t	*load_texture(t_game *game, char *png_path)
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
