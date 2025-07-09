/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:35:16 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/09 17:36:46 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

static int	get_tex_x(t_info *info, t_mlx *texture)
{
	int	tex_x;

	tex_x = get_wall_x(info);
	if (info->ray->side == 0 && info->ray->dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (info->ray->side == 1 && info->ray->dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

static void	draw_wall_line(t_info *info, t_mlx *texture, int x, t_draw draw)
{
	int	tex_y;
	int	color;

	while (draw.y < draw.end)
	{
		tex_y = (int)draw.tex_pos & (texture->height - 1);
		draw.tex_pos += draw.step;
		color = *(int *)(texture->adr + (tex_y * texture->size_line
					+ draw.tex_x * (texture->bpp / 8)));
		if (info->ray->side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(info->mlx, x, draw.y, color);
		draw.y++;
	}
}

static void	draw_textured_wall(t_info *info, int x, t_draw draw)
{
	t_mlx	*texture;

	texture = get_wall_texture(info);
	if (!texture || !texture->adr)
		return ;
	draw.tex_x = get_tex_x(info, texture);
	draw.step = 1.0 * texture->height / draw.line_height;
	draw.tex_pos = (draw.y - HEIGHT_DISPLAY / 2 + draw.line_height / 2)
		* draw.step;
	draw_wall_line(info, texture, x, draw);
}

void	draw_wall(t_info *info, int x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	t_draw	draw;

	line_height = (int)(HEIGHT_DISPLAY / info->ray->wall_dist);
	draw_start = -line_height / 2 + HEIGHT_DISPLAY / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT_DISPLAY / 2;
	if (draw_end >= HEIGHT_DISPLAY)
		draw_end = HEIGHT_DISPLAY - 1;
	draw.line_height = line_height;
	draw.y = draw_start;
	draw.end = draw_end;
	draw_textured_wall(info, x, draw);
}
