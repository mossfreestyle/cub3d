/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:17:05 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/03 20:52:24 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 2)
		return (check_arg("Only need a map", 1));
	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	if (init_all(info))
		return (error(info, "Problem during the initiation", 1));
	fill_stash(info, av);
	printf("NO = %s\n", info->assets->path_no);
	printf("SO = %s\n", info->assets->path_so);
	printf("EA = %s\n", info->assets->path_ea);
	printf("WE = %s\n", info->assets->path_we);
	for (int i = 0; i < 3; i++)
	{
		printf("C[%d] = %d\n", i, info->assets->ceiling_color[i]);
		printf("F[%d] = %d\n", i, info->assets->floor_color[i]);
	}
	// handle_events(info);
	// mlx_loop(info->mlx->mlx);
	// destroy_all(info);
	// free_all(info);
	return (0);
}
