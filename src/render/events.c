/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:05:23 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/09 17:33:13 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int keycode, t_info *info)
{
	if (keycode == XK_Escape)
		close_window(info);
	else if (keycode == XK_w || keycode == XK_W)
		info->key->press_w = true;
	else if (keycode == XK_s || keycode == XK_S)
		info->key->press_s = true;
	else if (keycode == XK_a || keycode == XK_A)
		info->key->press_a = true;
	else if (keycode == XK_d || keycode == XK_D)
		info->key->press_d = true;
	else if (keycode == XK_Left)
		info->key->press_turn_left = true;
	else if (keycode == XK_Right)
		info->key->press_turn_right = true;
	else if (keycode == XK_m || keycode == XK_M)
		info->minimap = !info->minimap;
	else if (keycode == XK_c || keycode == XK_C)
		info->controls = !info->controls;
	return (0);
}

int	key_release(int keycode, t_info *info)
{
	if (keycode == XK_w || keycode == XK_W)
		info->key->press_w = false;
	else if (keycode == XK_s || keycode == XK_S)
		info->key->press_s = false;
	else if (keycode == XK_a || keycode == XK_A)
		info->key->press_a = false;
	else if (keycode == XK_d || keycode == XK_D)
		info->key->press_d = false;
	else if (keycode == XK_Left)
		info->key->press_turn_left = false;
	else if (keycode == XK_Right)
		info->key->press_turn_right = false;
	else if (keycode == XK_KP_Add && info->map_scale < MAX_SCALE)
		info->map_scale++;
	else if (keycode == XK_KP_Subtract && info->map_scale > MIN_SCALE)
		info->map_scale--;
	return (0);
}

void	init_hooks(t_info *info)
{
	mlx_hook(info->mlx->window, KeyPress, KeyPressMask, key_press, info);
	mlx_hook(info->mlx->window, KeyRelease, KeyReleaseMask, key_release, info);
	mlx_hook(info->mlx->window, DestroyNotify, StructureNotifyMask,
		close_window, info);
	mlx_hook(info->mlx->window, ButtonPress, ButtonPressMask, mouse_press,
		info);
	mlx_hook(info->mlx->window, ButtonRelease, ButtonReleaseMask, mouse_release,
		info);
	mlx_hook(info->mlx->window, MotionNotify, PointerMotionMask, mouse_move,
		info);
}
