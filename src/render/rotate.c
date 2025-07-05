/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:59:03 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/05 16:31:55 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate(t_player *p, double angle)
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
	int delta_x;

	(void)y;
	if (!cub->key->key_down)
		return (0);
	delta_x = x - cub->key->x_old;
	if (delta_x != 0)
		rotate(&cub->player, delta_x * MOUSE_SENS);
	cub->key->x_old = x;
	return (0);
}