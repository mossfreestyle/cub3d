/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:51:02 by moss              #+#    #+#             */
/*   Updated: 2025/07/09 19:25:01 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_mouse(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

int	mouse_press(int button, int x, int y, t_info *cub)
{
	(void)y;
	if (button == 1)
	{
		cub->key->key_down = 1;
		cub->key->x_old = x;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_info *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
		cub->key->key_down = 0;
	return (0);
}

int	mouse_move(int x, int y, t_info *cub)
{
	static int	last_x = WIDTH_DISPLAY / 2;
	static int	initialized = 0;
	int			delta_x;

	(void)y;
	if (!initialized)
	{
		last_x = x;
		initialized = 1;
		return (0);
	}
	delta_x = x - last_x;
	if (abs(delta_x) > 2)
	{
		rotate(cub->player, delta_x * MOUSE_SENS);
		last_x = x;
		if (x < 100 || x > WIDTH_DISPLAY - 100)
		{
			mlx_mouse_move(cub->mlx->mlx, cub->mlx->window, WIDTH_DISPLAY / 2,
				HEIGHT_DISPLAY / 2);
			last_x = WIDTH_DISPLAY / 2;
		}
	}
	return (0);
}
