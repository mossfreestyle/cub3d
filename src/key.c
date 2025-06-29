/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:13:20 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/29 13:52:33 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_info(int keycode, void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (keycode == info->key->esc)
		is_esc(info);
	else if (keycode == info->key->key_w)
		is_w(info, info->player);
	else if (keycode == info->key->key_s)
		is_s(info, info->player);
	else if (keycode == info->key->key_a)
		is_a(info, info->player);
	else if (keycode == info->key->key_d)
		is_d(info, info->player);
	// move(info);
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
