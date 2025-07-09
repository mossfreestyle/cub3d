/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
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

static void	clear_image(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT_DISPLAY)
	{
		x = 0;
		while (x < WIDTH_DISPLAY)
		{
			put_pixel(info->mlx, x, y, BLACK);
			x++;
		}
		y++;
	}
}

static void	put_text(t_info *cub, char *text, int *y)
{
	int	x0;

	x0 = WIDTH_DISPLAY - 220;
	mlx_string_put(cub->mlx->mlx, cub->mlx->window, x0 + 1, *y + 1, BLACK,
		text);
	mlx_string_put(cub->mlx->mlx, cub->mlx->window, x0, *y, WHITE, text);
	*y += 15;
}

static void	draw_controls(t_info *cub)
{
	int	y;

	y = 20;
	put_text(cub, "         CONTROLS", &y);
	put_text(cub, " ", &y);
	put_text(cub, "Move        W A S D", &y);
	put_text(cub, "Rotate      < / >", &y);
	put_text(cub, "            Mouse (click & drag)", &y);
	put_text(cub, "Minimap     M     toggle", &y);
	put_text(cub, "            + / - resize", &y);
	put_text(cub, "Controls    C     toggle", &y);
	put_text(cub, "Quit        ESC", &y);
}

static void	draw_floor_ceiling(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT_DISPLAY / 2)
	{
		x = 0;
		while (x < WIDTH_DISPLAY)
		{
			put_pixel(info->mlx, x, y, info->assets->ceiling_col);
			x++;
		}
		y++;
	}
	y = HEIGHT_DISPLAY / 2;
	while (y < HEIGHT_DISPLAY)
	{
		x = 0;
		while (x < WIDTH_DISPLAY)
		{
			put_pixel(info->mlx, x, y, info->assets->floor_col);
			x++;
		}
		y++;
	}
}

void	render_frame(t_info *info)
{
	if (!info || !info->mlx || !info->mlx->img)
		return ;
	clear_image(info);
	draw_floor_ceiling(info);
	render_rays(info);
	if (info->minimap)
		draw_minimap(info);
	mlx_put_image_to_window(info->mlx->mlx, info->mlx->window, info->mlx->img,
		0, 0);
	if (info->controls)
		draw_controls(info);
}
