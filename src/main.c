/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:46:49 by linliu            #+#    #+#             */
/*   Updated: 2025/06/26 11:05:14 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main (int argc, char **argv)
{
	t_map	*game_map;

	if(argc != 2)
	{
		ft_putstr_fd("Error: give me one map\n", STDERR_FILENO);
		return(EXIT_FAILURE);
	}
	game_map = read_map(argv[1]);
	print_map(game_map);

	free_whole_map(game_map);
	return (0);
}

// void esc_hook(mlx_key_data_t keydata, void *param)
// {
// 	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ESCAPE)
// 		mlx_close_window((mlx_t *)param);
// }

// void close_hook(void *param)
// {
// 	mlx_close_window((mlx_t *)param);
// }

// int	main(int argc, char **argv)
// {
// 	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "so_long", false); // false, not fullscreen
// 	if (!mlx)
// 	{
// 		perror("mlx failed");
// 		exit(EXIT_FAILURE);
// 	}
// 	// //key
// 	mlx_key_hook(mlx, esc_hook, mlx);
// 	mlx_close_hook(mlx, close_hook, mlx);
// 	// //run
// 	mlx_loop(mlx);
// 	//stop
// 	mlx_terminate(mlx);
// }


// 	//creat a window

