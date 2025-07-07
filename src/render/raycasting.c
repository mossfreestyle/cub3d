/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:35:26 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/07 18:58:43 by rwassim          ###   ########.fr       */
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

static void	ray_step(t_info *cub, t_ray *ray)
{
    if (ray->dir_x < 0)
    {
        ray->step_x = -1;
        ray->s_dist_x = (cub->player->x - ray->map_x) * ray->d_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->s_dist_x = (ray->map_x + 1.0 - cub->player->x) * ray->d_dist_x;
    }
    if (ray->dir_y < 0)
    {
        ray->step_y = -1;
        ray->s_dist_y = (cub->player->y - ray->map_y) * ray->d_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->s_dist_y = (ray->map_y + 1.0 - cub->player->y) * ray->d_dist_y;
    }
}

static void	ray_init(t_info *cub, t_ray *ray, double camera_x)
{
	ray->dir_x = cub->player->dir_x + cub->player->plane_x * camera_x;
	ray->dir_y = cub->player->dir_y + cub->player->plane_y * camera_x;
	if (ray->dir_x == 0.0)
		ray->dir_x = EPS;
	if (ray->dir_y == 0.0)
		ray->dir_y = EPS;
	ray->map_x = (int)cub->player->x;
    ray->map_y = (int)cub->player->y; 
	ray->d_dist_x = fabs(1.0 / ray->dir_x);
	ray->d_dist_y = fabs(1.0 / ray->dir_y);
}

static void	cast_ray(t_info *g, double cam_x)
{
	t_ray	*r;
	double	delta;

	r = g->ray;
	ray_init(g, r, cam_x);
	ray_step(g, r);
	perf_dda(g, r);
	if (r->side == 0)
		delta = r->map_x - g->player->x + (1 - r->step_x) * 0.5;
	else
		delta = r->map_y - g->player->y + (1 - r->step_y) * 0.5;
	if (r->side == 0)
		r->wall_dist = delta / r->dir_x;
	else
		r->wall_dist = delta / r->dir_y;
	if (r->wall_dist < 0.01)
		r->wall_dist = 0.01;
}

void	render_rays(t_info *cub)
{
    int		x;
    double	cam_x;

    x = 0;
    while (x < WIDTH_DISPLAY)
    {
        cam_x = 2.0 * x / (double)WIDTH_DISPLAY - 1.0;
        ft_bzero(cub->ray, sizeof(t_ray));  // Correction
        cast_ray(cub, cam_x);
        draw_wall(cub, x);
        x++;
    }
}
