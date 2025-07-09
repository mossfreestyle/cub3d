/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:33:48 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/09 17:34:48 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_failure(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	error_exit(t_info *cub, char *msg)
{
	if (cub)
	{
		destroy_all(cub);
		free_all(cub);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	init_render_system(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	convert_colors_to_int(info);
	load_textures(info);
	while (++i < info->map_info->nb_lines)
	{
		j = 0;
		while (++j < info->map_info->line_max
			&& info->map_info->final_map[i][j])
		{
			if (ft_strchr("NSWE", info->map_info->final_map[i][j]))
			{
				info->player->x = j + 0.5;
				info->player->y = i + 0.5;
				set_player_direction(info, info->map_info->final_map[i][j]);
				info->map_info->final_map[i][j] = '0';
				return ;
			}
		}
	}
}
