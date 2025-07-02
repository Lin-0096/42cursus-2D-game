/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_play_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:39:54 by linliu            #+#    #+#             */
/*   Updated: 2025/07/02 23:55:15 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void	collect_items(t_game *game, int new_x, int new_y)
{
	size_t	i;

	i = 0;
	game->map->grid[new_y][new_x] = '0';
	while (i < game->tex.collectible->count)
	{
		if (game->tex.collectible->instances[i].x == new_x * TILE_SIZE && game->tex.collectible->instances[i].y == new_y * TILE_SIZE)
		{
			game->tex.collectible->instances[i].enabled = false;
			break ;
		}
		i++;
	}
	game->map->collectible--;
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	char	pos;

	pos = game->map->grid[new_y][new_x];
	if (pos == '1')
		return ;
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->tex.player->instances[0].x = new_x * TILE_SIZE;
	game->tex.player->instances[0].y = new_y * TILE_SIZE;
	game->moves_count++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves_count, 1);
	ft_putstr_fd("\n", 1);
	if (pos == 'E' && game->map->collectible <= 0)
		close_game(game, "You win!\n");
	else if (pos == 'C')
		collect_items(game, new_x, new_y);
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	if (keydata.action != MLX_PRESS)
		return ;
	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->mlx);
		close_game(game, "Closed by esc!\n");
	}
	x = game->map->player_x;
	y = game->map->player_y;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		move_player(game, x, y - 1);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		move_player(game, x, y + 1);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		move_player(game, x - 1, y);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		move_player(game, x + 1, y);
}
