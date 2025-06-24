/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:46:49 by linliu            #+#    #+#             */
/*   Updated: 2025/06/24 19:34:22 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// if(argc < 2)
	// {
	// 	ft_putstr_fd("No map!\n", STDERR_FILENO);
	// 	exit(EXIT_FAILURE);
	// }
	// if(argc > 2)
	// {
	// 	ft_putstr_fd("One map at a time!\n", STDERR_FILENO);
	// 	exit(EXIT_FAILURE);
	// }

	//creat a window
	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "so_long", false); // false, not fullscreen
	if (!mlx)
	{
		perror("mlx failed");
		exit(EXIT_FAILURE);
	}
	//key
	mlx_key_hook();
	mlx_close_hook();

	//run
	mlx_loop(mlx);
	//stop
	mlx_terminate(mlx);
}
