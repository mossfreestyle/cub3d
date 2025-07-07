/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:09:43 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/07 18:59:00 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_mlx *img, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x < WIDTH_DISPLAY && y >= 0 && y < HEIGHT_DISPLAY)
	{
		offset = (x * img->bpp / 8) + (y * img->size_line);
		*(int *)(img->adr + offset) = color;
	}
}

static void	put_text(t_info *cub, char *text, int *y)
{
    int	x0;

    x0 = WIDTH_DISPLAY - 220;
    mlx_string_put(cub->mlx->mlx, cub->mlx->window, x0 + 1, *y + 1, BLACK, text);
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

static void	draw_background(t_info *cub)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < HEIGHT_DISPLAY)
	{
		j = 0;
		if (i < HEIGHT_DISPLAY / 2)
			color = cub->assets->ceiling_col;
		else
			color = cub->assets->floor_col;
		while (j < WIDTH_DISPLAY)
		{
			put_pixel(cub->mlx, j, i, color);
			j++;
		}
		i++;
	}
}

void	render_frame(t_info *cub)
{
	draw_background(cub);
	render_rays(cub);
	if (cub->minimap)
		draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx->mlx, cub->mlx->window, cub->mlx->img, 0, 0);
	if (cub->controls)
		draw_controls(cub);
}
