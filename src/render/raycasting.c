/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
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

static void	init_ray(t_info *info, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH_DISPLAY - 1;
	info->ray->dir_x = info->player->dir_x + info->player->plane_x * camera_x;
	info->ray->dir_y = info->player->dir_y + info->player->plane_y * camera_x;
	info->ray->map_x = (int)info->player->x;
	info->ray->map_y = (int)info->player->y;
	if (info->ray->dir_x == 0)
		info->ray->d_dist_x = 1e30;
	else
		info->ray->d_dist_x = fabs(1.0 / info->ray->dir_x);
	if (info->ray->dir_y == 0)
		info->ray->d_dist_y = 1e30;
	else
		info->ray->d_dist_y = fabs(1.0 / info->ray->dir_y);
}

static void	calculate_step_and_side_dist(t_info *info)
{
	if (info->ray->dir_x < 0)
	{
		info->ray->step_x = -1;
		info->ray->s_dist_x = (info->player->x - info->ray->map_x)
			* info->ray->d_dist_x;
	}
	else
	{
		info->ray->step_x = 1;
		info->ray->s_dist_x = (info->ray->map_x + 1.0 - info->player->x)
			* info->ray->d_dist_x;
	}
	if (info->ray->dir_y < 0)
	{
		info->ray->step_y = -1;
		info->ray->s_dist_y = (info->player->y - info->ray->map_y)
			* info->ray->d_dist_y;
	}
	else
	{
		info->ray->step_y = 1;
		info->ray->s_dist_y = (info->ray->map_y + 1.0 - info->player->y)
			* info->ray->d_dist_y;
	}
}

static void	perform_dda(t_info *info)
{
	info->ray->hit = 0;
	while (info->ray->hit == 0)
	{
		if (info->ray->s_dist_x < info->ray->s_dist_y)
		{
			info->ray->s_dist_x += info->ray->d_dist_x;
			info->ray->map_x += info->ray->step_x;
			info->ray->side = 0;
		}
		else
		{
			info->ray->s_dist_y += info->ray->d_dist_y;
			info->ray->map_y += info->ray->step_y;
			info->ray->side = 1;
		}
		if (info->map_info->final_map[info->ray->map_y][info->ray->map_x]
					== '1')
			info->ray->hit = 1;
	}
}

static void	calculate_wall_distance(t_info *info)
{
	if (info->ray->side == 0)
		info->ray->wall_dist = (info->ray->map_x - info->player->x + (1
					- info->ray->step_x) / 2) / info->ray->dir_x;
	else
		info->ray->wall_dist = (info->ray->map_y - info->player->y + (1
					- info->ray->step_y) / 2) / info->ray->dir_y;
}

void	render_rays(t_info *info)
{
	int	x;

	x = 0;
	while (x < WIDTH_DISPLAY)
	{
		init_ray(info, x);
		calculate_step_and_side_dist(info);
		perform_dda(info);
		calculate_wall_distance(info);
		draw_wall(info, x);
		x++;
	}
}
