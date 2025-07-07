/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:37:20 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/07 18:51:45 by rwassim          ###   ########.fr       */
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

int	check_map_is_last(t_info *info, char **map)
{
	int	i;

	i = 0;
	while (only_white_spaces(map[i]))
		i++;
	while (is_valid(info, map[i]))
		i++;
	while (map[i])
	{
		if (!only_white_spaces(map[i]))
			return (1);
		i++;
	}
	return (0);
}

void	print_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

static int	is_invalid_position(char **map, int y, int x, int len)
{
	if (y == 0 || !map[y + 1] || x == 0 || x == len - 1)
		return (1);
	if (y > 0)
	{
		if (x >= (int)ft_strlen(map[y - 1]) || map[y - 1][x] == 'X')
			return (1);
	}
	if (map[y + 1])
	{
		if (x >= (int)ft_strlen(map[y + 1]) || map[y + 1][x] == 'X')
			return (1);
	}
	if ((x > 0 && map[y][x - 1] == 'X') || (x < len - 1 && map[y][x
			+ 1] == 'X'))
		return (1);
	return (0);
}

int	check_is_closed(t_info *info, char **map)
{
	int	len;
	int	y;
	int	x;

	(void)info;
	if (!map)
		return (1);
	y = 0;
	while (map[y])
	{
		len = ft_strlen(map[y]);
		x = 0;
		while (x < len)
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'O')
				if (is_invalid_position(map, y, x, len))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
