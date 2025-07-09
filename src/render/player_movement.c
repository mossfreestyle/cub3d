/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
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

static int	is_valid_position(t_info *info, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || map_x >= info->map_info->line_max
		|| map_y >= info->map_info->nb_lines)
		return (0);
	if (info->map_info->final_map[map_y][map_x] == '1'
		|| info->map_info->final_map[map_y][map_x] == 'X')
		return (0);
	return (1);
}

void	move_forward(t_info *info)
{
	double	new_x;
	double	new_y;

	new_x = info->player->x + info->player->dir_x * MOVE_SPEED;
	new_y = info->player->y + info->player->dir_y * MOVE_SPEED;
	if (is_valid_position(info, new_x, info->player->y))
		info->player->x = new_x;
	if (is_valid_position(info, info->player->x, new_y))
		info->player->y = new_y;
}

void	move_backward(t_info *info)
{
	double	new_x;
	double	new_y;

	new_x = info->player->x - info->player->dir_x * MOVE_SPEED;
	new_y = info->player->y - info->player->dir_y * MOVE_SPEED;
	if (is_valid_position(info, new_x, info->player->y))
		info->player->x = new_x;
	if (is_valid_position(info, info->player->x, new_y))
		info->player->y = new_y;
}

void	strafe_left(t_info *info)
{
	double	new_x;
	double	new_y;

	new_x = info->player->x - info->player->plane_x * MOVE_SPEED;
	new_y = info->player->y - info->player->plane_y * MOVE_SPEED;
	if (is_valid_position(info, new_x, info->player->y))
		info->player->x = new_x;
	if (is_valid_position(info, info->player->x, new_y))
		info->player->y = new_y;
}

void	strafe_right(t_info *info)
{
	double	new_x;
	double	new_y;

	new_x = info->player->x + info->player->plane_x * MOVE_SPEED;
	new_y = info->player->y + info->player->plane_y * MOVE_SPEED;
	if (is_valid_position(info, new_x, info->player->y))
		info->player->x = new_x;
	if (is_valid_position(info, info->player->x, new_y))
		info->player->y = new_y;
}
