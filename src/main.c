/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:46:49 by linliu            #+#    #+#             */
/*   Updated: 2025/07/03 15:49:51 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Give me one map\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	game.map = read_map(argv[1]);
	game.mlx = mlx_init(game.map->width * TILE_SIZE,
			game.map->height * TILE_SIZE, "MEOW", false);
	if (!game.mlx)
		terminate_with_error(&game, "mlx initialized failed\n");
	game.moves_count = 0;
	init_texture(&game);
	render_game(&game);
	mlx_key_hook(game.mlx, handle_input, &game);
	mlx_close_hook(game.mlx, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}

