/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:13:20 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/28 23:45:27 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_info(t_info *info, int keycode)
{
	t_player	*player;

	player = info->player;
	if (keycode == info->key->key_w)
        is_w(info, player);
	else if (keycode == info->key->key_s)
        is_s(info, player);
	else if (keycode == info->key->key_a)
        is_a(info, player);
	else if (keycode == info->key->key_d)
        is_d(info, player);
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
