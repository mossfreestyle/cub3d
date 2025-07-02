/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:37:20 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/03 00:48:15 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	ft_strlenlen(char **tab)
{
	int	i;

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
	while (only_white_spaces(info->map_info->stash[i]))
		i++;
	while (is_valid(info, info->map_info->stash[i]))
		i++;
	while (info->map_info->stash[i])
	{
		if (!only_white_spaces(info->map_info->stash[i]))
			return (1);
		i++;
	}
	return (0);
}


int	check_is_closed(t_info *info, char **map)
{
	int	len;

	int y, x;
	y = -1;
	while (map[++y])
	{
		len = ft_strlen(map[y]);
		x = -1;
		while (++x < len)
		{
			if (map[y][x] == '0' || map[x][y] == info->player->view)
			{
				if (y == 0 || !map[y + 1] || x == 0
					|| x == (int)ft_strlen(map[y]) - 1)
					return (1);
				if (x >= (int)ft_strlen(map[y - 1]) || map[y - 1][x] == ' '
					|| x >= (int)ft_strlen(map[y + 1]) || map[y + 1][x] == ' '
					|| map[y][x - 1] == ' ' || x + 1 >= (int)ft_strlen(map[y])
					|| map[y][x + 1] == ' ')
					return (1);
			}
		}
	}
	return (0);
}
