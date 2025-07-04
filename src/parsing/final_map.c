/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:26:16 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/04 16:10:19 by mfernand         ###   ########.fr       */
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

void	set_up_final_map(t_info *info)
{
	int	i;

	i = -1;
	init_some_data(info);
	info->map_info->final_map = malloc(sizeof(char *)
			* (get_nb_lines(info->map_info->first_map) + 1));
	if (check_is_closed(info, info->map_info->first_map))
		error(info, "The map is not closed by only wall", 1);
	info->map_info->closed = true;
	if (!info->map_info->final_map)
		error(info, "ff\n", 1);
	while (info->map_info->first_map[++i])
	{
		info->map_info->final_map[i] = ft_strjoin_to_line_max(info->map_info->first_map[i],
				info->map_info->line_max);
		if (!info->map_info->final_map[i])
			error(info, "Problem when replacing empty char for final map", 1);
	}
	info->map_info->final_map[i] = NULL;
	// if (check_is_closed(info, info->map_info->final_map))
		// error(info, "The map is not closed by only wall", 1);
	// if (check_is_closed(info, info->map_info->final_map))
	// 	error(info, "The map is not closed by only wall", 1);
	info->map_info->closed = true;
	info->map_info->x_max = info->map_info->line_max - 1;
	info->map_info->y_max = (int)ft_strlenlen(info->map_info->final_map) - 1;
	info->map_info->nb_lines = info->map_info->y_max + 1;
}
