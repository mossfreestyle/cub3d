/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:37:20 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/02 12:41:46 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	ft_strlenlen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
// 	int is_spawn(char c)
// {
//     return (c == 'N' || c == 'S' || c == 'E' || c == 'O');
// }


int	check_map_is_last(t_info *info)
{
	int	i;

	i = 0;
	while (only_white_spaces(info->map_info->first_map[i]))
		i++;
	while (is_valid(info, info->map_info->first_map[i]))
		i++;
	while (info->map_info->first_map[i])
	{
		if (!only_white_spaces(info->map_info->first_map[i]))
			return (1);
		i++;
	}
	return (0);
}




int	check_is_closed(t_info *info, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!map[y + 1] || map[0])
			{
			}
		}
	}
}

// int	check_is_closed(t_info *info, char **map)
// {
//     int	y, x;
//     int	len;

//     for (y = 0; map[y]; y++)
//     {
//         len = ft_strlen(map[y]);
//         for (x = 0; x < len; x++)
//         {
//             if (map[y][x] == '0' || is_spawn(map[y][x]))
//             {
//                 // Vérifie si sur un bord vertical ou horizontal
//                 if (y == 0 || !map[y + 1] || x == 0
// || x == (int)ft_strlen(map[y]) - 1)
// //                     return (1); // Pas fermé
// //
// // Vérifie si une case adjacente n'existe pas ou est un espace ou hors ligne
// //                 if (x >= (int)ft_strlen(map[y - 1]) || map[y
	// - 1][x] == ' '
// ||
// 	//                     x >= (int)ft_strlen(map[y + 1]) || map[y
// 		+ 1][x] == ' '
// 	||
// 	//                     map[y][x - 1] == ' ' ||
// 	//                     x + 1 >= (int)ft_strlen(map[y]) || map[y][x
// 		+ 1] == ' ')
// 	//                     return (1); // Pas fermé
// 	//             }
// 	//         }
// 	//     }
// 	//     return (0); // OK
// 	// }

