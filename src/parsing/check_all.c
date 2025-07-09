/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:20:19 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/09 17:25:05 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_around(char **map, size_t i, size_t j)
{
	if (i == 0 || j == 0 || i == ft_strlenlen(map) - 1 || j == ft_strlen(map[i])
		- 1)
		return (1);
	if ((map[i - 1][j] == '1' || is_player_char(map[i - 1][j]) || map[i
			- 1][j] == '0' || map[i - 1][j] == 'V') && (map[i + 1][j] == '1'
			|| is_player_char(map[i + 1][j]) || map[i + 1][j] == '0' || map[i
			+ 1][j] == 'V') && (map[i][j - 1] == '1' || is_player_char(map[i][j
				- 1]) || map[i][j - 1] == '0' || map[i][j - 1] == 'V')
		&& (map[i][j + 1] == '1' || is_player_char(map[i][j + 1]) || map[i][j
			+ 1] == '0' || map[i][j + 1] == 'V'))
		return (0);
	return (1);
}

void	check_surrounded(t_info *info, char **map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == (char)info->player->view)
				if (check_around(map, (int)i, (int)j))
					error(info, "map not close", 1);
		}
	}
}

void	equal_line(t_info *info, char **map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map[++i])
	{
		info->map_info->final_map[i] = malloc(sizeof(char)
				* info->map_info->line_max + 1);
		if (!info->map_info->final_map[i])
			error(info, "malloc failed", 1);
		j = -1;
		while (map[i][++j])
		{
			if (ft_isspace(map[i][j]))
				info->map_info->final_map[i][j] = v_or_x(info, map, (int)i,
						(int)j);
			else if (map[i][j] == '\n')
				break ;
			else
				info->map_info->final_map[i][j] = map[i][j];
		}
		add_x(info, i, (int)j);
	}
	info->map_info->final_map[i] = NULL;
	check_surrounded(info, info->map_info->final_map);
}
