/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:26:16 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/02 14:20:53 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	set_up_final_map(t_info *info)
{
	int		i;
	char	*old_line;

	i = -1;
	old_line = NULL;
	info->map_info->line_max = find_longuest_line(info->map_info->final_map);
	if (check_is_closed(info, info->map_info->final_map))
		error(info, "The map is not closed by only wall\n", 1);
	info->map_info->closed = true;
	while (info->map_info->final_map[++i])
	{
		old_line = info->map_info->final_map[i];
		info->map_info->final_map[i] = ft_strjoin_to_line_max(old_line,
				info->map_info->line_max);
		free(old_line);
		if (!info->map_info->final_map[i])
			error(info, "Problem when replacing empty char for final map\n", 1);
	}
	info->map_info->x_max = info->map_info->line_max - 1;
	info->map_info->y_max = (int)ft_strlenlen(info->map_info->final_map) - 1;
	info->map_info->nb_lines = info->map_info->y_max + 1;
}
