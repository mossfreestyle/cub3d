/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
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

void	put_pixel(t_mlx *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH_DISPLAY || y >= HEIGHT_DISPLAY)
		return ;
	dst = img->adr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_rgb_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	convert_colors_to_int(t_info *info)
{
	info->assets->floor_col = create_rgb_color(info->assets->floor_color[0],
			info->assets->floor_color[1], info->assets->floor_color[2]);
	info->assets->ceiling_col = create_rgb_color(info->assets->ceiling_color[0],
			info->assets->ceiling_color[1], info->assets->ceiling_color[2]);
}
