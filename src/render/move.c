/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:14:47 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/07 18:58:32 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	try_move(t_info *cub, double new_x, double new_y)
{
    if (cub->map_info->final_map[(int)new_y][(int)new_x] != '1')
    {
        cub->player->x = new_x;
        cub->player->y = new_y;
    }
}

void	move_forward(t_info *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->x + cub->player->dir_x * MOVE_SPEED;
	new_y = cub->player->y + cub->player->dir_y * MOVE_SPEED;
	try_move(cub, new_x, new_y);
}

void	move_backward(t_info *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->x - cub->player->dir_x * MOVE_SPEED;
	new_y = cub->player->y - cub->player->dir_y * MOVE_SPEED;
	try_move(cub, new_x, new_y);
}

void	strafe_right(t_info *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->x + cub->player->plane_x * MOVE_SPEED;
	new_y = cub->player->y + cub->player->plane_y * MOVE_SPEED;
	try_move(cub, new_x, new_y);
}

void	strafe_left(t_info *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->x - cub->player->plane_x * MOVE_SPEED;
	new_y = cub->player->y - cub->player->plane_y * MOVE_SPEED;
	try_move(cub, new_x, new_y);
}
