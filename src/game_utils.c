/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:05:57 by linliu            #+#    #+#             */
/*   Updated: 2025/06/30 22:27:52 by linliu           ###   ########.fr       */
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
