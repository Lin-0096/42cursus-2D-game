/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:05:57 by linliu            #+#    #+#             */
/*   Updated: 2025/07/01 17:45:15 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	terminate_with_error(t_game *game, char *str)
{
	cleanup_image(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_error_handle(game->map, str);
}

void	cleanup_image(t_game *game)
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

void	close_game(t_game *game, char *str)
{
	cleanup_image(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map);
		free_whole_map(game->map);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("Thanks for playing game!\n", 1);
	exit(EXIT_SUCCESS);
}
