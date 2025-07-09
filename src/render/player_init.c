/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/07/07 19:00:00 by rwassim          #+#    #+#             */
/*   Updated: 2025/07/07 19:00:00 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_direction_north(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

static void	set_direction_south(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

static void	set_direction_east(t_player *player)
{
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

static void	set_direction_west(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

void	set_player_direction(t_info *info, char c)
{
	if (c == 'N')
	{
		info->player->view = N;
		set_direction_north(info->player);
	}
	else if (c == 'S')
	{
		info->player->view = S;
		set_direction_south(info->player);
	}
	else if (c == 'E')
	{
		info->player->view = E;
		set_direction_east(info->player);
	}
	else if (c == 'W')
	{
		info->player->view = W;
		set_direction_west(info->player);
	}
}
