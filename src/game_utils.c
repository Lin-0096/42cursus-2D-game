/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:05:57 by linliu            #+#    #+#             */
/*   Updated: 2025/07/01 18:01:47 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* mlx_load_png() Decode/load a PNG file into a buffer.
mlx_texture_t* mlx_load_png(const char* path);

mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture) It converts a texture into an image that can be drawn in your game window. ;

mlx_delete_texture(tex)； i don't need it anymore

mlx_image_to_window(mlx, img, x, y); Put the image into your game window
*/

static mlx_image_t	*load_texture(t_game *game, char *png_path)
{
	mlx_texture_t *tmp;
	mlx_image_t	*img;

	tmp = mlx_load_png(png_path);
	if (!tmp)
		terminate_with_error(game, "fail to load png\n");
	img = mlx_texture_to_image(game->mlx, tmp);
	mlx_delete_texture(tmp);
	if (!img)
		return (NULL);
	return (img);
}

void	init_texture(t_game *game)
{
	game->tex.wall = load_texture(game, WALL);
	if (!game->tex.wall)
		terminate_with_error(game, "fail to convert wall texture\n");
	game->tex.floor = load_texture(game, FLOOR);
	if (!game->tex.floor)
		terminate_with_error(game, "fail to convert floor texture\n");
	game->tex.player = load_texture(game, PLAYER);
	if (!game->tex.player)
		terminate_with_error(game, "fail to convert player texture\n");
	game->tex.exit = load_texture(game, EXIT);
	if (!game->tex.exit)
		terminate_with_error(game, "fail to convert exit texture\n");
	game->tex.collectible = load_texture(game, COLLECTIBLE);
	if (!game->tex.collectible)
		terminate_with_error(game, "fail to convert collectible texture\n");
}

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
	if (game->map)
		free_whole_map(game->map);
	if (str && *str)
		ft_putstr_fd(str, 1);
	ft_putstr_fd("Thanks for playing game!\n", 1);
	exit(EXIT_SUCCESS);
}
