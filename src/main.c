/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:46:49 by linliu            #+#    #+#             */
/*   Updated: 2025/06/25 13:56:03 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main (int argc, char **argv)
{
	if(argc < 2)
	{
		ft_putstr_fd("No map!\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if(argc > 2)
	{
		ft_putstr_fd("One map at a time!\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	char **map = read_map(argv[1]);
	print_map(map);
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

// 	int fd = open(argv[1], O_RDONLY);
// 	int i = 0;
// 	char *new_line = get_next_line(fd);
// 	while (new_line)
// 	{
// 		i++;
// 		free(new_line);
// 		new_line = get_next_line(fd);
// 	}
// 	close(fd);
// 	fd = open(argv[1], O_RDONLY);
// 	int line = i;
// 	char **map = malloc(sizeof(char *) * (line + 1));
// 	if (!map)
// 		return (NULL);
// 	i = 0;
// 	while (i < line)
// 		map[i++] = get_next_line(fd);
// 	map[line] = NULL; //!!
// 	close(fd);
// }


// 	//creat a window

