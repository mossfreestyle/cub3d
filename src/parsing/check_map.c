/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:36:36 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/04 02:02:01 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_some_data(t_info *info)
{
	info->map_info->line_max = find_longuest_line(info->map_info->first_map);
	info->map_info->nb_lines = get_nb_lines(info->map_info->first_map);
	info->map_info->nb_players = get_nb_players(info,
			info->map_info->first_map);
	if (info->map_info->nb_players != 1)
		error(info, "Wrong number of players", 1);
}

char	**parse_map(t_info *info)
{
	int		i;
	char	**tab;
	int		j;

	i = -1;
	j = 0;
	init_some_data(info);
	tab = malloc(sizeof(char *) * (info->map_info->nb_lines + 1));
	if (!tab)
		error(info, "Error when during the allocation of the map", 1);
	while (++i < info->map_info->nb_lines)
	{
		if (!only_white_spaces(info->map_info->first_map[i])
			&& info->map_info->first_map[i][0] != '\n' && !is_valid(info,
				info->map_info->first_map[i]))
			error(info, "Invalid character in map", 1);
		tab[j] = ft_strdup(info->map_info->first_map[i]);
		if (!tab[j++])
		{
			free_tab(tab);
			error(info, "Error of allocation when add empty char the map", 1);
		}
	}
	return (tab[j] = NULL, tab);
}
