/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:17:05 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/06 01:29:24 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	print_all(t_info *info);

int	main(int ac, char **av)
{
	t_info	*info;
	int		len;

	if (ac != 2)
		return (check_arg("Only need a map.cub", 1));
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(av[1] + len - 4, ".cub", 4))
		return (check_arg("Only need a map.cub", 1));
	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	if (init_all(info))
		return (error(info, "Problem during the initialisation", 1));
	fill_stash(info, av);
	if (init_mlx(info->mlx))
		return (error(info, "Problem during the initialisation", 1));
	// print_all(info);
	handle_events(info);
	mlx_loop(info->mlx->mlx);
	destroy_all(info);
	free_all(info);
	return (0);
}


// static void	print_all(t_info *info)
// {
// 	printf("NO=%s\n", info->assets->path_no);
// 	printf("SO=%s\n", info->assets->path_so);
// 	printf("EA=%s\n", info->assets->path_ea);
// 	printf("WE=%s\n", info->assets->path_we);
// 	for (int i = 0; i < 3; i++)
// 		printf("C[%d]=%d\n", i, info->assets->ceiling_color[i]);
// 	for (int j = 0; j < 3; j++)
// 		printf("F[%d]=%d\n", j, info->assets->floor_color[j]);
// 	printf("VALID=%d\n\n", info->valid_assets);
// 	 printf("PLAYER_VIEW = ");
//     if (info->player->view == N)
//         printf("N (North)\n");
//     else if (info->player->view == S)
//         printf("S (South)\n");
//     else if (info->player->view == E)
//         printf("E (East)\n");
//     else if (info->player->view == W)
//         printf("W (West)\n");
//     else
//         printf("UNKNOWN\n");
//     printf("SPAWN_POS = (%d, %d)\n", info->map_info->x_spawn, info->map_info->y_spawn);
// 	print_map(info->map_info->first_map);
// 	printf("\n\n===================================\n\n");
// 	print_map(info->map_info->final_map);
// }
