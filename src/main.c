/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:46:49 by linliu            #+#    #+#             */
/*   Updated: 2025/07/01 17:55:51 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main (int argc, char **argv)
{
	t_game	game;

	if(argc != 2)
	{
		ft_putstr_fd("Error: give me one map\n", STDERR_FILENO);
		return(EXIT_FAILURE);
	}
	game.map = read_map(argv[1]);
	game.mlx = mlx_init(game.map->height * TILE_SIZE, game.map->width * TILE_SIZE, "MEOW", false);
	if (!game.mlx)
		terminate_with_error(&game, "mlx initialized failed\n");
	init_texture(&game); //png->texture->image
	render_game(&game); //image->windoow
	print_map(game.map, &game);
	mlx_key_hook(game.mlx, handle_input, &game); //play game

	// //run
	mlx_loop(game.mlx);
	//stop
	mlx_terminate(game.mlx); //should I delete image before terminate, or just use close_game func?

	free_whole_map(game.map);
	return (0);
}

