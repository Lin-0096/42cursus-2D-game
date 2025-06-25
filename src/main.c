/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:46:49 by linliu            #+#    #+#             */
/*   Updated: 2025/06/25 08:14:34 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void esc_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window((mlx_t *)param);
}
void close_hook(void *param)
{
	mlx_close_window((mlx_t *)param);
}
int	main(void)
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
	// (void)argv;
	//creat a window
	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "so_long", false); // false, not fullscreen
	if (!mlx)
	{
		perror("mlx failed");
		exit(EXIT_FAILURE);
	}
	// //key
	mlx_key_hook(mlx, esc_hook, mlx);
	mlx_close_hook(mlx, close_hook, mlx);
	// //run
	mlx_loop(mlx);
	//stop
	mlx_terminate(mlx);
}
