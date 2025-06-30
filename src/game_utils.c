/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:05:57 by linliu            #+#    #+#             */
/*   Updated: 2025/06/30 18:24:19 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	terminate_with_error(t_game *game, char *str)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_error_handle(game->map, str);
}
