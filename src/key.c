/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:13:20 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/07 18:50:56 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_info(int keycode, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (keycode == XK_Escape)
		is_esc(info);
	else if (keycode == XK_w || keycode == XK_W)
		is_w(info, info->player);
	else if (keycode == XK_s || keycode == XK_S)
		is_s(info, info->player);
	else if (keycode == XK_a || keycode == XK_A)
		is_a(info, info->player);
	else if (keycode == XK_d || keycode == XK_D)
		is_d(info, info->player);
	return (0);
}

void	reset_key(t_info *info)
{
	t_key	*key_pressed;

	key_pressed = info->key;
	key_pressed->press_w = False;
	key_pressed->press_s = False;
	key_pressed->press_a = False;
	key_pressed->press_d = False;
	key_pressed->press_turn_left = False;
	key_pressed->press_turn_right = False;
}
