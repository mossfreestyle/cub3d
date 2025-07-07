/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:52:59 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/07 18:57:59 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	clamp_int(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

static void	get_line_limits(int *start, int *end, int line_h)
{
	*start = HEIGHT_DISPLAY / 2 - line_h / 2;
	if (*start < 0)
		*start = 0;
	*end = HEIGHT_DISPLAY / 2 + line_h / 2;
	if (*end >= HEIGHT_DISPLAY)
		*end = HEIGHT_DISPLAY - 1;
}

static int	get_pixel_color(t_mlx *wall, int tex_x, int tex_y)
{
	int		bpp;
	char	*src;

	bpp = wall->bpp / 8;
	src = wall->adr + tex_y * wall->size_line + tex_x * bpp;
	return (*(int *)src);
}

static void	draw_column(t_info *g, t_mlx *wall, int x, int line_h)
{
	int	start;
	int	end;
	int	tex_x;
	int	tex_y;
	int	color;

	get_line_limits(&start, &end, line_h);
	tex_x = get_tex_x(g->ray, wall, g->player);
	while (start <= end)
	{
		tex_y = get_tex_y(start, line_h, wall->height);
		color = get_pixel_color(wall, tex_x, tex_y);
		put_pixel(g->mlx, x, start, color);
		start++;
	}
}

void	draw_wall(t_info *g, int x)
{
    t_ray	*ray;
    int		line_h;

    ray = g->ray;
    line_h = (int)(HEIGHT_DISPLAY / ray->wall_dist);
    if (ray->side == 0)
    {
        if (ray->dir_x > 0)
            draw_column(g, g->assets->ea, x, line_h);
        else
            draw_column(g, g->assets->we, x, line_h);
    }
    else
    {
        if (ray->dir_y > 0)
            draw_column(g, g->assets->so, x, line_h);
        else
            draw_column(g, g->assets->no, x, line_h);
    }
}
