/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:44:43 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/07 18:58:38 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_north(t_info *cub)
{
	cub->player->dir_x = 0.0;
	cub->player->dir_y = -1.0;
	cub->player->plane_x = 0.66;
	cub->player->plane_y = 0.0;
}

static void	set_south(t_info *cub)
{
	cub->player->dir_x = 0.0;
	cub->player->dir_y = 1.0;
	cub->player->plane_x = -0.66;
	cub->player->plane_y = 0.0;
}

static void	set_east(t_info *cub)
{
	cub->player->dir_x = 1.0;
	cub->player->dir_y = 0.0;
	cub->player->plane_x = 0.0;
	cub->player->plane_y = 0.66;
}

static void	set_west(t_info *cub)
{
	cub->player->dir_x = -1.0;
	cub->player->dir_y = 0.0;
	cub->player->plane_x = 0.0;
	cub->player->plane_y = -0.66;
}

void	set_player_direction(t_info *cub, char c)
{
	if (c == 'N')
		set_north(cub);
	else if (c == 'S')
		set_south(cub);
	else if (c == 'E')
		set_east(cub);
	else if (c == 'W')
		set_west(cub);
}
