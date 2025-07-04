/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:17:05 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/04 02:21:08 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_info	*info;
	int		len;

	len = ft_strlen(av[1]);
	if (ac != 2 || len < 4 || ft_strncmp(av[1] + len - 4, ".cub", 4))
		return (check_arg("Only need a map.cub", 1));
	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	if (init_all(info))
		return (error(info, "Problem during the initiation", 1));
	fill_stash(info, av);
	// handle_events(info);
	// mlx_loop(info->mlx->mlx);
	// destroy_all(info);
	// free_all(info);
	return (0);
}
