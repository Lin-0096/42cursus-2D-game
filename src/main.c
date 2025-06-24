/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:46:49 by linliu            #+#    #+#             */
/*   Updated: 2025/06/24 17:18:53 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
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
	(void)argv;

}
