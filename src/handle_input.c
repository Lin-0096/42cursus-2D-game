/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:52:36 by linliu            #+#    #+#             */
/*   Updated: 2025/07/01 18:36:36 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_next_position(mlx_key_data_t keydata, t_game *game, int *next_x, int *next_y)
{
	*next_x = game->map->player_x;
	*next_y = game->map->player_y;

	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		(*next_y)--;
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		(*next_y)++;
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		(*next_x)--;
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		(*next_x)++;
}

static void	update_player_position(t_game *game, int next_x, int next_y)
{
	int	old_x;
	int	old_y;

	old_x = game->map->player_x;
	old_y = game->map->player_y;
	game->map->grid[old_y][old_x] = '0';
	game->map->player_x = next_x;
	game->map->player_y = next_y;
	game->map->grid[next_y][next_x] = 'P';
}
static int	check_and_update_player_position(t_game *game, int next_x, int next_y)
{
	char	pos;

	pos = game->map->grid[next_y][next_x];
	if (pos == '1')
		return (0);
	if (pos == 'C')
	{
		game->map->collectible--;
		game->map->grid[next_y][next_x] = '0';
		update_player_position(game, next_x, next_y);
	}
	else if (pos == 'E')
	{
		if (game->map->collectible <= 0)
		{
			update_player_position(game, next_x, next_y);
			return (1);
		}
		return (0);
	}
	else
		update_player_position(game, next_x, next_y);
	return (0);
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		next_x;
	int		next_y;
	int		gamewon;

	if (keydata.action != MLX_PRESS) //check press first
		return ;
	game = (t_game *)param; //pass value
	if (keydata.key == MLX_KEY_ESCAPE) //handle esc
	{
		mlx_close_window(game->mlx);
		close_game(game, "Closed by esc!\n");
	}
	get_next_position(keydata, game, &next_x, &next_y);
	gamewon = check_and_update_player_position(game, next_x, next_y);
	game->moves_count++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves_count, 1);
	ft_putstr_fd("\n", 1);
	render_game(game);
	if (gamewon)
		close_game(game, "You win!\n");
}


