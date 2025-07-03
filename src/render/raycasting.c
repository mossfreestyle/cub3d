/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:35:26 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/03 21:05:12 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	perf_dda(t_info *cub, t_ray *ray)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->s_dist_x < ray->s_dist_y)
		{
			ray->s_dist_x += ray->d_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->s_dist_y += ray->d_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (cub->map_info->final_map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}
