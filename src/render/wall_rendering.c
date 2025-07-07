/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:00:00 by rwassim          #+#    #+#             */
/*   Updated: 2025/07/07 19:00:00 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_mlx	*get_wall_texture(t_info *info)
{
	if (info->ray->side == 0)
	{
		if (info->ray->dir_x > 0)
			return (info->assets->ea);
		else
			return (info->assets->we);
	}
	else
	{
		if (info->ray->dir_y > 0)
			return (info->assets->so);
		else
			return (info->assets->no);
	}
}

static int	get_wall_x(t_info *info)
{
	double	wall_x;

	if (info->ray->side == 0)
		wall_x = info->player->y + info->ray->wall_dist * info->ray->dir_y;
	else
		wall_x = info->player->x + info->ray->wall_dist * info->ray->dir_x;
	
	wall_x -= floor(wall_x);
	return ((int)(wall_x * (double)info->assets->no->width));
}

static void	draw_textured_wall(t_info *info, int x, int line_height, 
	int draw_start, int draw_end)
{
	t_mlx	*texture;
	int		tex_x;
	int		tex_y;
	int		y;
	double	step;
	double	tex_pos;
	int		color;

	texture = get_wall_texture(info);
	if (!texture || !texture->adr)
		return ;
	
	tex_x = get_wall_x(info);
	if (info->ray->side == 0 && info->ray->dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (info->ray->side == 1 && info->ray->dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	
	step = 1.0 * texture->height / line_height;
	tex_pos = (draw_start - HEIGHT_DISPLAY / 2 + line_height / 2) * step;
	
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = *(int *)(texture->adr + (tex_y * texture->size_line 
			+ tex_x * (texture->bpp / 8)));
		if (info->ray->side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(info->mlx, x, y, color);
		y++;
	}
}

void	draw_wall(t_info *info, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(HEIGHT_DISPLAY / info->ray->wall_dist);
	
	draw_start = -line_height / 2 + HEIGHT_DISPLAY / 2;
	if (draw_start < 0)
		draw_start = 0;
	
	draw_end = line_height / 2 + HEIGHT_DISPLAY / 2;
	if (draw_end >= HEIGHT_DISPLAY)
		draw_end = HEIGHT_DISPLAY - 1;
	
	draw_textured_wall(info, x, line_height, draw_start, draw_end);
}
